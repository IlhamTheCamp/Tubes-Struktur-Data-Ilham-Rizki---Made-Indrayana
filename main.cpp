#include <iostream>
#include "flight.h"
#include "child.h"
#include "parent.h"
#include "relation.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    ListChild L1;
    createListCh(L1);
    insertFirstCh(L1, allocateCh("Singapore Airlines","3"));
    insertFirstCh(L1, allocateCh("Garuda Indonesia","9"));
    adrChild Prec = firstChild(L1);
    //cout << maskapai(Prec);
    insertAfterCh(L1, Prec, allocateCh("KLM","88"));
    insertLastCh(L1, allocateCh("Emirates","77"));
    printChild(L1);
    adrChild C;
    deleteFirstCh(L1,C);
    deleteLastCh(L1,C);
    Prec = firstChild(L1);
    deleteAfterCh(L1, Prec, C);
    printChild(L1);
    return 0;
}
