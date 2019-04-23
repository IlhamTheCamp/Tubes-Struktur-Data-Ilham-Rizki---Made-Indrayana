#include "child.h"

void createListCh (ListChild &L)
{
    firstChild(L) = NULL;
    lastChild(L) = NULL;
}

adrChild allocateCh (string maskapai, string IDChild)
{
    adrChild C = new elmChild;
    maskapai(C) = maskapai;
    IDChild(C) = IDChild;
    nextChild(C) = NULL;
    prevChild(C) = NULL;
    return C;
}

void deallocateChild (adrChild &P)
{
    delete P;
}

void insertFirstCh (ListChild &L, adrChild C)
{
    if (firstChild(L) != NULL)
    {
        nextChild(C) = firstChild(L);
        prevChild(firstChild(L)) = C;
        firstChild(L) = C;
    }
    else
    {
        firstChild(L) = C;
        lastChild(L) = C;
    }
}

void insertAfterCh (ListChild &L, adrChild Prec, adrChild C)
{
    nextChild(C) = nextChild(Prec);
    prevChild(C) = Prec;
    prevChild(nextChild(Prec)) = C;
    nextChild(Prec) = C;
}

void insertLastCh (ListChild &L, adrChild C)
{
    if (firstChild(L)!= NULL)
    {
        prevChild(C) = lastChild(L);
        nextChild(lastChild(L)) = C;
        lastChild(L) = C;
    }
    else
    {
        insertFirstCh(L,C);
    }
}

void deleteFirstCh (ListChild &L, adrChild &C)
{
    C = firstChild(L);
    firstChild(L) = nextChild(firstChild(L));
    prevChild(C) = NULL;
    prevChild(firstChild(L)) = NULL;
    nextChild(C) = NULL;
}

void deleteAfterCh (ListChild &L, adrChild &Prec, adrChild C)
{
    C = nextChild(Prec);
    nextChild(Prec) = nextChild(C);
    prevChild(nextChild(C)) = Prec;
    prevChild(C) = NULL;
    nextChild(C) = NULL;
}

void deleteLastCh (ListChild &L, adrChild &C)
{
    if (firstChild(L) == lastChild(L))
    {
        deleteFirstCh(L,C);
    }
    else
    {
        lastChild(L) = prevChild(lastChild(L));
        prevChild(C) = NULL;
        nextChild(lastChild(L)) = NULL;
    }
}

adrChild searchChild (ListChild L, string IDC)
{
    adrChild C = firstChild(L);
    while (IDC != IDChild(C) && C != NULL)
    {
        C = nextChild(C);
    }
    return C;
}
