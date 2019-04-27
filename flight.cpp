#include "flight.h"
/// add later just in case we wanna change it

void insertParent (ListParent &L){
    int ID;
    string Tujuan;
    cout << "ID     : ";
    cin >> ID;
    cin.ignore();
    cout << "Tujuan : ";
    getline(cin, Tujuan);
    adrParent P = allocatePar(Tujuan, ID);
    if (searchParent(L, ID)==NULL){
        if ((firstParent(L)==NULL)||(IDParent(P)<IDParent(firstParent(L)))) {
            insertFirstPar(L, P);
            cout << "a ";
        } else if (IDParent(P)>IDParent(lastParent(L))) {
            insertLastPar(L, P);
            cout << "b ";
        } else {
            adrParent Q = firstParent(L);
            while (IDParent(nextParent(Q))<IDParent(P)) {
                Q = nextParent(Q);
                cout << "nye ";
            }
            insertAfterPar(L, Q, P);
            cout << "c ";
        }
        cout << "Success" << endl;
    } else {
        deallocatePar(P);
        cout << "Nope" << endl;
    }

}

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

void insertChild (ListChild &L)
{
    int IDanak;
    string Maskapai;
    cout << "ID : ";
    cin >> IDanak;
    cin.ignore();
    cout << "Maskapai : ";
    getline(cin, Maskapai);
    adrChild C = allocateCh(Maskapai, IDanak);
    if (searchChild(L, IDanak)==NULL){
        if ((firstChild(L)==NULL)||(IDChild(C)<IDChild(firstChild(L)))) {
            insertFirstCh(L, C);
            cout << "a ";
        } else if (IDChild(C)>IDChild(lastChild(L))) {
            insertLastCh(L, C);
            cout << "b ";
        } else {
            adrChild Q = firstChild(L);
            while (IDChild(nextChild(Q))<IDChild(C)) {
                Q = nextChild(Q);
                cout << "nye ";
            }
            insertAfterCh(L, Q, C);
            cout << "c ";
        }
        cout << "Success" << endl;
    } else {
        deallocateCh(C);
        cout << "Nope" << endl;
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
    }
    else
    {
        cout << "nope" << endl; //Remove later
    }
}

void connect (ListParent &P, ListChild C, int IDP, int IDC)
{
    adrParent Par = searchParent(P, IDP);
    adrChild Chi = searchChild(C, IDC);
    if (Par!=NULL && Chi!=NULL)
    {
        adrRelation R = allocateRel(Chi);
        insertRel(childList(Par), R);
    }
}

bool checkConnection (ListParent P, ListChild C, int IDP, int IDC)
{
    adrParent Par = searchParent(P, IDP);
    adrChild Chi = searchChild(C, IDC);
    if (Par!=NULL && Chi!=NULL)
    {
        adrRelation R = firstRelation(childList(Par));
        while (R!=NULL)
        {
            if (Chi == child(R))
            {
                return true;
            }
            R = nextRelation(R);
        }
    }
    return false;
}

void disconnect (ListParent &P, ListChild C, int IDP, int IDC)
{
    adrParent Par = searchParent(P, IDP);
    adrChild Chi = searchChild(C, IDC);
    if (Par!=NULL && Chi!=NULL)
    {
        adrRelation R = firstRelation(childList(Par));;
        if (child(R) == Chi)
        {
            deleteFirstRel(childList(Par), R);
            deallocateRel(R);
        }
        else
        {
            adrRelation S = R;
            while (S!=NULL&&child(nextRelation(S))!=Chi)
            {
                S = nextRelation(S);
            }
            deleteAfterRel(childList(Par), S, R);
            deallocateRel(R);
        }
    }
}

void printAll (ListParent P, ListChild C)
{
    adrParent Q = firstParent(P);
    adrRelation R;
    while (Q!=NULL)
    {
        cout << tujuan(Q) << " :" << endl;
        R = firstRelation(childList(Q));
        if (R==NULL)
        {
            cout << " [Empty]" << endl;
        }
        else
        {
            while (R!=NULL)
            {
                cout << " -> " << maskapai(child(R)) << endl;
                R = nextRelation(R);
            }
        }
        Q = nextParent(Q);
    }
    cout << endl;
}

void printChildOfParent (ListParent P, ListChild C, int IDP)
{
    adrParent Q = searchParent(P,IDP);
    if (Q != NULL)
    {
        cout << "Child dari Parent " << tujuan(Q) << " (" << IDP << ") adalah : " << endl;
        adrRelation R = firstRelation(childList(Q));
        if (R==NULL)
        {
            cout << " [Empty] " << endl;
        }
        else
        {
            while (R != NULL)
            {
                cout << " -> " << maskapai(child(R)) << endl;
                R = nextRelation(R);
            }
        }
    }
}

void deleteChild (ListParent &P, ListChild &C){
    int ID;
    cout << "ID : ";
    cin >> ID;
    adrChild PrevC, Chi = searchChild(C, ID);
    if (Chi!=NULL) {
        adrParent Par = firstParent(P);
        while (Par!=NULL) {
            adrRelation temp, Rel = firstRelation(childList(Par));
            while (Rel!=NULL) {
                if (child(Rel) == Chi) {
                    Rel = nextRelation(Rel);
                    deleteFirstRel(childList(Par), temp);
                    deallocateRel(temp);
                } else if (nextRelation(Rel)!=NULL&&child(nextRelation(Rel)) == Chi) {
                    deleteAfterRel(childList(Par),Rel, temp);
                    deallocateRel(temp);
                } else {
                    Rel = nextRelation(Rel);
                }
            }
            Par = nextParent(Par);
        }
        if (Chi==firstChild(C)) {
            deleteFirstCh(C, Chi);
        } else {
            PrevC = prevChild(Chi);
            deleteAfterCh(C, PrevC, Chi);
        }
        deallocateCh(Chi);
    }
};
