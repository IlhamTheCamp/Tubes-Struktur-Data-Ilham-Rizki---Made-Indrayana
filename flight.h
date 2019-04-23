#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "parent.h"
#include "child.h"
#include "relation.h"

using namespace std;

void insertParent (ListParent &L);
void printParent (ListParent L);
void insertChild (ListParent &L);
void printChild (ListChild L);
void connect (ListParent &P, ListChild C);
void checkConnection (ListParent P, ListChild C); // not sure
void disconnect (ListParent &P, ListChild C);
void printAll (ListParent P, ListChild C);
void printChildOfParent (ListParent P, ListChild C);
void deleteChild (ListParent &P, ListChild &C);
void deleteParent (ListParent $L);

#endif // FLIGHT_H_INCLUDED
