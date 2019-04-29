#include "relation.h"
#include "child.h"
// MADE INDRAYANA PUTRA
void createListRel (ListRelation &L)
{
    firstRelation(L) = NULL;
}

adrRelation allocateRel (adrChild C)
{
    adrRelation R = new elmRelation;
    child(R) = C;
    nextRelation(R) = NULL;
    return R;
}

void deallocateRel (adrRelation R)
{
    delete R;
}

void insertRel (ListRelation &L, adrRelation R)
{
    nextRelation(R) = firstRelation(L);
    firstRelation(L) = R;
}

void deleteFirstRel (ListRelation &L, adrRelation &R)
{
    R = firstRelation(L);
    firstRelation(L) = nextRelation(R);
    nextRelation(R) = NULL;
}

void deleteAfterRel (ListRelation &L, adrRelation Prec, adrRelation &R)
{
    if (Prec!=NULL && nextRelation(Prec)!=NULL)
    {
        R = nextRelation(Prec);
        nextRelation(Prec) = nextRelation(R);
        nextRelation(R) = NULL;
    }
}
