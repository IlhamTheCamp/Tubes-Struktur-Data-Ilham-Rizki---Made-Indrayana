#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "relation.h"

#define IDParent(P) P->IDParent
#define tujuan(P) P->tujuan
#define nextParent(P) P->nextParent
#define prevParent(P) P->prevParent
#define childList(P) P->childList
#define firstParent(L) L.firstParent
#define lastParent(L) L.lastParent

using namespace std;

typedef struct elmParent *adrParent;

struct elmParent{
    string IDParent;
    string tujuan;
    ListRelation childList;
    adrParent nextParent;
    adrParent prevParent;
};

struct ListParent{
    adrParent firstParent;
    adrParent lastParent;
};

void createListPar (ListParent &L);
adrParent allocatePar (string tujuan, string IDParent);
void deallocatePar (adrParent &P);
void insertFirstPar (ListParent &L, adrParent P);
void insertAfterPar (ListParent &L, adrParent P);
void insertLastPar (ListParent &L, adrParent P);
void deleteFirstPar (ListParent &L, adrParent &P);
void deleteAfterPar (ListParent &L, adrParent &P);
void deleteLastPar (ListParent &L, adrParent &P);
adrParent searchParent (ListParent L, string ID);

#endif // PARENT_H_INCLUDED
