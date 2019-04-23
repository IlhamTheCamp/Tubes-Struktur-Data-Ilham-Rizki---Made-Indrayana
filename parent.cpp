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

}

void insertAfterPar (ListParent &L, adrParent P)
{

}

void insertLastPar (ListParent &L, adrParent P)
{

}

void deleteFirstPar (ListParent &L, adrParent &P)
{

}

void deleteAfterPar (ListParent &L, adrParent &P)
{

}

void deleteLastPar (ListParent &L, adrParent &P)
{

}

adrParent searchParent (ListParent L, string ID)
{

}
