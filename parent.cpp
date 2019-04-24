#include "parent.h"
#include "relation.h"

void createListPar (ListParent &L)
{
    firstParent(L) = NULL;
    lastParent(L) = NULL;
}

adrParent allocatePar (string tujuan, string IDParent)
{
    adrParent P = new elmParent;
    tujuan(P) = tujuan;
    IDParent(P) = IDParent;
    createListRel(childList(P));
    nextParent(P) = NULL;
    prevParent(P) = NULL;
    return P;
}

void deallocatePar (adrParent &P)
{
    delete P;
}

void insertFirstPar (ListParent &L, adrParent P)
{
    if (firstParent(L) != NULL)
    {
        nextParent(P) = firstParent(L);
        prevParent(firstParent(L)) = P;
        firstParent(L) = P;
    }
    else
    {
        firstParent(L) = P;
        lastParent(L) = P;
    }
}

void insertAfterPar (ListParent &L, adrParent Prec, adrParent P)
{
    if ((Prec!=NULL)&&(P!=NULL))
    {
        if (nextParent(Prec)!=NULL)
        {
            nextParent(P) = nextParent(Prec);
            prevParent(P) = Prec;
            prevParent(nextParent(Prec)) = P;
            nextParent(Prec) = P;
        }
        else
        {
            insertLastPar(L, P);
        }
    }
}

void insertLastPar (ListParent &L, adrParent P)
{
    if (firstParent(L) != NULL)
    {
        prevParent(P) = lastParent(L);
        nextParent(lastParent(L)) = P;
        lastParent(L) = P;
    }
    else
    {
        firstParent(L) = P;
        lastParent(L) = P;
    }
}

void deleteFirstPar (ListParent &L, adrParent &P)
{
    if (firstParent(L)!=NULL)
    {
        P = firstParent(L);
        if (firstParent(L) == lastParent(L))
        {
            firstParent(L) = NULL;
            lastParent(L) = NULL;
        }
        else
        {
            firstParent(L) = nextParent(P);
            prevParent(firstParent(L)) = NULL;
            nextParent(P) = NULL;
        }
    }
}

void deleteAfterPar (ListParent &L, adrParent Prec, adrParent &P)
{
    if (Prec!=NULL)
    {
        P = nextParent(Prec);
        if (nextParent(P) != NULL)
        {
            nextParent(Prec) = nextParent(P);
            prevParent(nextParent(P)) = Prec;
            prevParent(P) = NULL;
            nextParent(P) = NULL;
        }
        else
        {
            deleteLastPar(L, P);
        }
    }
}

void deleteLastPar (ListParent &L, adrParent &P)
{
    if (firstParent(L)!=NULL)
    {
        P = lastParent(L);
        if (firstParent(L) == lastParent(L))
        {
            firstParent(L) = NULL;
            lastParent(L) = NULL;
        }
        else
        {
            lastParent(L) = prevParent(P);
            nextParent(lastParent(L)) = NULL;
            prevParent(P) = NULL;
        }
    }
}

adrParent searchParent (ListParent L, string IDP)
{
    adrParent P = firstParent(L);
    while (P != NULL && IDP != IDParent(P))
    {
        P = nextParent(P);
    }
    return P;
}
