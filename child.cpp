#include "child.h"

void createListCh (ListChild &L)
{
    firstChild(L) = NULL;
    lastChild(L) = NULL;
}

adrChild allocateCh (string maskapai, int IDChild)
{
    adrChild C = new elmChild;
    maskapai(C) = maskapai;
    IDChild(C) = IDChild;
    nextChild(C) = NULL;
    prevChild(C) = NULL;
    return C;
}

void deallocateCh (adrChild &C)
{
    delete C;
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
    if ((Prec!=NULL)&&(C!=NULL))
    {
        if (nextChild(Prec)!=NULL)
        {
            nextChild(C) = nextChild(Prec);
            prevChild(C) = Prec;
            prevChild(nextChild(Prec)) = C;
            nextChild(Prec) = C;
        }
        else
        {
            insertLastCh(L, C);
        }
    }
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
        firstChild(L) = C;
        lastChild(L) = C;
    }
}

void deleteFirstCh (ListChild &L, adrChild &C)
{
    if (firstChild(L)!=NULL)
    {
        C = firstChild(L);
        if (firstChild(L) == lastChild(L))
        {
            firstChild(L) = NULL;
            lastChild(L) = NULL;
        }
        else
        {
            firstChild(L) = nextChild(C);
            prevChild(firstChild(L)) = NULL;
            nextChild(C) = NULL;
        }
    }
}

void deleteAfterCh (ListChild &L, adrChild &Prec, adrChild C)
{
    if (Prec!=NULL)
    {
        C = nextChild(Prec);
        if (nextChild(C) != NULL)
        {
            nextChild(Prec) = nextChild(C);
            prevChild(nextChild(C)) = Prec;
            prevChild(C) = NULL;
            nextChild(C) = NULL;
        }
        else
        {
            deleteLastCh(L, C);
        }
    }
}

void deleteLastCh (ListChild &L, adrChild &C)
{
    if (lastChild(L)!=NULL)
    {
        C = lastChild(L);
        if (firstChild(L) == lastChild(L))
        {
            firstChild(L) = NULL;
            lastChild(L) = NULL;
        }
        else
        {
            lastChild(L) = prevChild(C);
            nextChild(lastChild(L)) = NULL;
            prevChild(C) = NULL;
        }
    }
}

adrChild searchChild (ListChild L, int IDC)
{
    adrChild C = firstChild(L);
    while (C != NULL && IDC != IDChild(C) )
    {
        C = nextChild(C);
    }
    return C;
}
