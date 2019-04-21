#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#define tujuan(P) P->tujuan
#define IDParent(P) P->IDParent
#define nextParent(P) P->nextParent
#define maskapai(C) C->maskapai
#define IDChild(C) C->IDChild
#define nextChild(C) C->nextChild
#define nextRelation(V) V->nextRelation
#define firstParent(L) L.firstParent
#define firstChild(L) L.firstChild
#define firstRelation(L) L.firstRelation

using namespace std;
typedef struct elmParent *adrParent;
typedef struct elmChild *adrChild;
typedef struct elmRelation *adrRelation;

struct elmParent{
    string tujuan;
    string IDParent;
    adrParent nextParent;
};

struct ListParent{
    adrParent firstParent;
};

struct elmChild{
    string maskapai;
    string IDChild;
    adrChild nextChild;
};

struct ListChild{
    adrChild firstChild;
};

struct elmRelation{
    adrChild nextChild;
    adrRelation nextRelation;
};

struct ListRelation{
    adrRelation firstRelation;
};

void createListParent (ListParent &L);
void createListChild (ListChild &L);
void createListRelation (ListRelation &L);
adrParent allocateParent (string tujuan, string IDParent);
adrChild allocateChild (string maskapai, string IDChild);
void deallocateParent (adrParent &P);
void deallocateChild (adrChild &P);
#endif // FLIGHT_H_INCLUDED
