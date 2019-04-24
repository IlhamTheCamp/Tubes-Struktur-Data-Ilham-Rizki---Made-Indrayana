#include <iostream>
#include "flight.h"
#include "child.h"
#include "parent.h"
#include "relation.h"

using namespace std;

int main()
{
    cout << "Welcome to Bojongsoang International Airport!" << endl;

    ListChild L1;
    createListCh(L1);
    insertFirstCh(L1, allocateCh("Singapore Airlines","3"));
    insertFirstCh(L1, allocateCh("Garuda Indonesia","9"));
    insertAfterCh(L1, searchChild(L1,"3"), allocateCh("KLM","88"));
    insertLastCh(L1, allocateCh("Emirates","77"));
    printChild(L1);
    adrChild C;
    /*deleteFirstCh(L1,C);
    deleteLastCh(L1,C);
    adrChild Prec = searchChild(L1,"3");
    deleteAfterCh(L1, Prec, C);
    printChild(L1);*/
    cout << endl;
    ListParent L2;
    createListPar(L2);
    insertFirstPar(L2, allocatePar("Tokyo","22"));
    insertFirstPar(L2, allocatePar("Jakarta","45"));
    insertAfterPar(L2, searchParent(L2,"22"), allocatePar("London","99"));
    insertLastPar(L2, allocatePar("Bali","100"));
    printParent(L2);
    adrParent P;
    /*deleteFirstPar(L2,P);
    deleteLastPar(L2,P);
    adrParent PrecP = searchParent(L2,"22");
    deleteAfterPar(L2,PrecP,P);
    printParent(L2);*/
    connect(L2, L1, "22", "77");
    connect(L2, L1, "100", "77");
    connect(L2, L1, "100", "9");
    connect(L2, L1, "99", "3");
    connect(L2, L1, "45", "3");
    connect(L2, L1, "99", "77");
    connect(L2, L1, "99", "88");
    connect(L2, L1, "1", "1");      //Error Testing
    connect(L2, L1, "100", "1");    //Error Testing
    connect(L2, L1, "1", "9");      //Error Testing
    printAll(L2, L1);
    disconnect(L2, L1, "99", "77");
    printAll(L2, L1);
    /// :o
    return 0;
}
