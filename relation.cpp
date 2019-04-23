#include "relation.h"
#include "child.h"

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

void deleteRel (ListRelation &L, adrRelation &R)
{
    /// i just realized this is complicated
}
