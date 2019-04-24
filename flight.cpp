#include "flight.h"
/// add later just in case we wanna change it
void printParent (ListParent L)
{
    if (firstParent(L) != NULL)
    {
        adrParent P = firstParent(L);
        while (P != NULL)
        {
            cout << tujuan(P) << " - ";
            P = nextParent(P);
        }
        cout << "done" << endl; //Remove done when finished
    }
    else
    {
        cout << "nope" << endl; //Remove later
    }
}

void printChild(ListChild L)
{
    if (firstChild(L) != NULL)
    {
        adrChild C = firstChild(L);
        while (C != NULL)
        {
            cout << maskapai(C) << " - ";
            C = nextChild(C);
        }
        cout << "done" << endl; //Remove done when finished
    } else {
        cout << "nope" << endl; //Remove later
}

void connect (ListParent &P, ListChild C, string IDP, string IDC){
    adrParent Par = searchParent(P, IDP);
    adrChild Chi = searchChild(C, IDC);
    if (Par!=NULL && Chi!=NULL) {
        adrRelation R = allocateRel(Chi);
        insertRel(childList(Par), R);
    }
}

adrRelation checkConnection (ListParent P, ListChild C, string IDP, string IDC){
    adrParent Par = searchParent(P, IDP);
    adrChild Chi = searchChild(C, IDC);
    if (Par!=NULL && Chi!=NULL) {
        adrRelation R = firstRelation(childList(Par));
        while (R!=NULL) {
            if (Chi == child(R)) {
                return R;
            }
            R = nextRelation(R);
        }
    }
    return NULL;
}

void disconnect (ListParent &P, ListChild C, string IDP, string IDC){
    adrParent Par = searchParent(P, IDP);
    adrChild Chi = searchChild(C, IDC);
    if (Par!=NULL && Chi!=NULL) {
        adrRelation R = firstRelation(childList(Par));;
        if (child(R) == Chi) {
            deleteFirstRel(childList(Par), R);
            deallocateRel(R);
        } else {
            adrRelation S = R;
            while (S!=NULL&&child(nextRelation(S))!=Chi) {
                S = nextRelation(S);
            }
            deleteAfterRel(childList(Par), S, R);
            deallocateRel(R);
        }
    }
};

