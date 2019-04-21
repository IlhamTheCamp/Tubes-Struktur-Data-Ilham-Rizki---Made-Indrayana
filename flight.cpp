#include "flight.h"
void createListParent (ListParent &L)
{
    firstParent(L) = NULL;
}
void createListChild (ListChild &L)
{
    firstChild(L) = NULL;
}
void createListRelation (ListRelation &L)
{
    firstRelation(L) = NULL;
}
adrParent allocateParent (string tujuan, string IDParent)
{
    adrParent P = new elmParent;
    tujuan(P) = tujuan;
    IDParent(P) = IDParent;
    nextParent(P) = NULL;
    return P;
}
adrChild allocateChild (string maskapai, string IDChild)
{
    adrChild P = new elmChild;
    maskapai(P) = maskapai;
    IDChild(P) = IDChild;
    nextChild(P) = NULL;
    return P;
}
void deallocateParent (adrParent &P)
{
    delete P;
}
void deallocateChild (adrChild &P)
{
    delete P;
}
