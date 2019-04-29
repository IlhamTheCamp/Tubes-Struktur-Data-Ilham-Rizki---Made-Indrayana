#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
// MADE INDRAYANA PUTRA
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

struct elmParent
{
    int IDParent;
    string tujuan;
    ListRelation childList;
    adrParent nextParent;
    adrParent prevParent;
};

struct ListParent
{
    adrParent firstParent;
    adrParent lastParent;
};

void createListPar (ListParent &L);
adrParent allocatePar (string tujuan, int IDParent);
void deallocatePar (adrParent &P);
void insertFirstPar (ListParent &L, adrParent P);
void insertAfterPar (ListParent &L, adrParent Prec, adrParent P);
void insertLastPar (ListParent &L, adrParent P);
void deleteFirstPar (ListParent &L, adrParent &P);
void deleteAfterPar (ListParent &L, adrParent Prec, adrParent &P);
void deleteLastPar (ListParent &L, adrParent &P);
adrParent searchParent (ListParent L, int IDP);

#endif // PARENT_H_INCLUDED
