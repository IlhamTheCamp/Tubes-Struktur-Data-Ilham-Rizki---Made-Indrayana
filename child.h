#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define IDChild(C) C->IDChild
#define maskapai(C) C->maskapai
#define diskon(C) C->diskon
#define nextChild(C) C->nextChild
#define prevChild(C) C->prevChild
#define firstChild(L) L.firstChild
#define lastChild(L) L.lastChild

using namespace std;

typedef struct elmChild *adrChild;

struct elmChild
{
    int IDChild;
    string maskapai;
    int diskon;
    adrChild nextChild;
    adrChild prevChild;
};

struct ListChild
{
    adrChild firstChild;
    adrChild lastChild;
};

void createListCh (ListChild &L);
adrChild allocateCh (string maskapai, int IDChild, int diskon);
void deallocateCh (adrChild &C);
void insertFirstCh (ListChild &L, adrChild C);
void insertAfterCh (ListChild &L, adrChild Prec, adrChild C);
void insertLastCh (ListChild &L, adrChild C);
void deleteFirstCh (ListChild &L, adrChild &C);
void deleteAfterCh (ListChild &L, adrChild &Prec, adrChild C);
void deleteLastCh (ListChild &L, adrChild &C);
adrChild searchChild (ListChild L, int IDC);

#endif // CHILD_H_INCLUDED
