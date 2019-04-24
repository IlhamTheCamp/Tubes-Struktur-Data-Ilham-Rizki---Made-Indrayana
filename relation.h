#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "child.h"

#define child(R) R->child
#define nextRelation(R) R->nextRelation
#define firstRelation(L) L.firstRelation

using namespace std;

typedef struct elmRelation *adrRelation;

struct elmRelation
{
    adrChild child;
    adrRelation nextRelation;
};

struct ListRelation
{
    adrRelation firstRelation;
};

void createListRel (ListRelation &L);
adrRelation allocateRel (adrChild C);
void deallocateRel (adrRelation R);
void insertRel (ListRelation &L, adrRelation R);
void deleteFirstRel (ListRelation &L, adrRelation &R);
void deleteAfterRel (ListRelation &L, adrRelation Prec, adrRelation &R);

#endif // RELATION_H_INCLUDED
