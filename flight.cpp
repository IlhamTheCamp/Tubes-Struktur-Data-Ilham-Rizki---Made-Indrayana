#include "flight.h"
/// add later just in case we wanna change it
void printParent (ListParent L)
{
    if (firstParent(L) != NULL)
    {
        adrParent P = firstParent(L);
        while (P != NULL)
        {
            cout << tujuan(P) << " - ";
            P = nextParent(P);
        }
        cout << "done" << endl;
    }
    else
    {
        cout << "nope" << endl;
    }
}

void printChild(ListChild L)
{
    if (firstChild(L) != NULL)
    {
        adrChild C = firstChild(L);
        while (C != NULL)
        {
            cout << maskapai(C) << " - ";
            C = nextChild(C);
        }
        cout << "done" << endl;
    } else {
        cout << "nope" << endl;
    }
}
