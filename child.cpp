#include "child.h"

adrChild allocateChild (string maskapai, string IDChild)
{
    adrChild P = new elmChild;
    maskapai(P) = maskapai;
    IDChild(P) = IDChild;
    nextChild(P) = NULL;
    return P;
}

void deallocateChild (adrChild &P)
{
    delete P;
}
