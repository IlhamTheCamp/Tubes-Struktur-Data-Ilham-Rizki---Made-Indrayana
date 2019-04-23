#include "child.h"

void createListCh (ListChild &L)
{
    firstChild(L) = NULL;
    lastChild(L) = NULL;
}

adrChild allocateChild (string maskapai, string IDChild)
{
    adrChild P = new elmChild;
    maskapai(P) = maskapai;
    IDChild(P) = IDChild;
    nextChild(P) = NULL;
    prevChild(P) = NULL;
    return P;
}

void deallocateChild (adrChild &P)
{
    delete P;
}

void insertFirstCh (ListChild &L, adrChild C)
{

}

void insertAfterCh (ListChild &L, adrChild C)
{

}

void insertLastCh (ListChild &L, adrChild C)
{

}

void deleteFirstCh (ListChild &L, adrChild &C)
{

}

void deleteAfterCh (ListChild &L, adrChild &C)
{

}

void deleteLastCh (ListChild &L, adrChild &C)
{

}

adrChild searchChild (ListChild L, string ID)
{

}
