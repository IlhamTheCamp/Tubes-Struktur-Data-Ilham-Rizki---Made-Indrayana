#include "flight.h"
/// add later just in case we wanna change it

void insertParent (ListParent &L){
    int ID;
    string Tujuan;
    cout << "ID : ";
    cin >> ID;
    cin.ignore();
    cout << "Destination : ";
    getline(cin, Tujuan);
    adrParent P = allocatePar(Tujuan, ID);
    if (searchParent(L, ID)==NULL){
        if ((firstParent(L)==NULL)||(IDParent(P)<IDParent(firstParent(L)))) {
            insertFirstPar(L, P);
        } else if (IDParent(P)>IDParent(lastParent(L))) {
            insertLastPar(L, P);
        } else {
            adrParent Q = firstParent(L);
            while (IDParent(nextParent(Q))<IDParent(P)) {
                Q = nextParent(Q);
            }
            insertAfterPar(L, Q, P);
        }
        cout << "Successfully Inserted!" << endl;
    } else {
        deallocatePar(P);
        cout << "Failed! ID Already Exist!" << endl;
    }

}

void printParent (ListParent L)
{
    if (firstParent(L) != NULL)
    {
        adrParent P = firstParent(L);
        while (P != NULL)
        {
            cout << IDParent(P) << ") " << tujuan(P) << endl;
            P = nextParent(P);
        }
    }
    else
    {
        cout << "[Empty]" << endl;
    }
}

void insertChild (ListChild &L)
{
    int IDanak;
    string Maskapai;
    int diskonPromo;
    cout << "ID : ";
    cin >> IDanak;
    cin.ignore();
    cout << "Airlines : ";
    getline(cin, Maskapai);
    cout << "Discount (%) : ";
    cin >> diskonPromo;
    adrChild C = allocateCh(Maskapai, IDanak, diskonPromo);
    if (searchChild(L, IDanak)==NULL){
        if ((firstChild(L)==NULL)||(IDChild(C)<IDChild(firstChild(L)))) {
            insertFirstCh(L, C);
        } else if (IDChild(C)>IDChild(lastChild(L))) {
            insertLastCh(L, C);
        } else {
            adrChild Q = firstChild(L);
            while (IDChild(nextChild(Q))<IDChild(C)) {
                Q = nextChild(Q);
            }
            insertAfterCh(L, Q, C);
        }
        cout << "Successfully Inserted!" << endl;
    } else {
        deallocateCh(C);
        cout << "Failed! ID Already Exist!" << endl;
    }
}

void printChild(ListChild L)
{
    if (firstChild(L) != NULL)
    {
        adrChild C = firstChild(L);
        while (C != NULL)
        {
            cout << IDChild(C) << ") " << maskapai(C) << endl;
            C = nextChild(C);
        }
    }
    else
    {
        cout << "[Empty]" << endl; //Remove later
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
        cout << "Successfully Added!" << endl;
    }
    if (Par == NULL) {
        cout << "Failed! Destination Doesn't Exist!" << endl;
    }
    if (Chi == NULL) {
        cout << "Failed! Airlines Doesn't Exist!" << endl;
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
        cout << "Successfully Deleted!" << endl;
    }
    if (Par == NULL) {
        cout << "Failed! Destination Doesn't Exist!" << endl;
    }
    if (Chi == NULL) {
        cout << "Failed! Airlines Doesn't Exist!" << endl;
    }
}

void printAll (ListParent P, ListChild C)
{
    adrParent Q = firstParent(P);
    adrRelation R;
    while (Q!=NULL)
    {
        cout << IDParent(Q) << ") " << tujuan(Q) << " :" << endl;
        R = firstRelation(childList(Q));
        if (R==NULL)
        {
            cout << " [Empty]" << endl;
        }
        else
        {
            while (R!=NULL)
            {
                cout << " -> " << IDChild(child(R)) << ") " << maskapai(child(R)) << endl;
                R = nextRelation(R);
            }
        }
        Q = nextParent(Q);
    }
    cout << endl;
}

adrRelation biggestPromo (ListParent P, ListChild C, int IDP)
{
    adrParent Q = searchParent(P, IDP);
    adrRelation R, temp;
    if (Q!=NULL)
    {
        temp = firstRelation(childList(Q));
        R = nextRelation(temp);
        while (R != NULL)
        {
            if (diskon(child(R)) > diskon(child(temp)))
            {
                temp = R;
            }
            R = nextRelation(R);
        }
    }
    return temp;
}

void printChildOfParent (ListParent P, ListChild C, int IDP)
{
    adrParent Q = searchParent(P,IDP);
    if (Q != NULL)
    {
        cout << "Airlines leaving for " << tujuan(Q) << " (" << IDP << ") are : " << endl;
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
    } else {
        cout << "Failed! Destination Doesn't Exist!" << endl;
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
        }
        else if (Chi == lastChild(C))
        {
            deleteLastCh(C, Chi);
        }
        else {
            PrevC = prevChild(Chi);
            deleteAfterCh(C, PrevC, Chi);
        }
        deallocateCh(Chi);
        cout << "Successfully Deleted!" << endl;
    } else {
        cout << "Failed! Airlines Doesn't Exist!" << endl;
    }
};

void deleteParent(ListParent &P)
{
    int ID;
    cout << "ID : ";
    cin >> ID;
    adrParent Par = searchParent(P, ID);
    if (Par != NULL)
    {
        adrRelation temp, Rel = firstRelation(childList(Par));
        while (Rel != NULL)
        {
            temp = Rel;
            Rel = nextRelation(Rel);
            deleteFirstRel(childList(Par),temp);
            deallocateRel(temp);
        }
        if (Par == firstParent(P))
        {
            deleteFirstPar(P,Par);
        }
        else if (Par == lastParent(P))
        {
            deleteLastPar(P,Par);
        }
        else
        {
            adrParent PrevP = prevParent(Par);
            deleteAfterPar(P, PrevP, Par);
        }
        deallocatePar(Par);
        cout << "Successfully Deleted!" << endl;
    } else {
        cout << "Failed! Destination Doesn't Exist!" << endl;
    }
}


int totalFlight (ListParent P, ListChild C)
{
    adrParent Q = firstParent(P);
    adrRelation R;
    int jumlah = 0;
    while (Q!=NULL)
    {
        R = firstRelation(childList(Q));
        while (R!=NULL)
        {
            jumlah++;
            R = nextRelation(R);
        }
        Q = nextParent(Q);
    }
    return jumlah;
}
