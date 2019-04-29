#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "parent.h"
#include "child.h"
#include "relation.h"

using namespace std;

void insertParent (ListParent &L); // MADE INDRAYANA PUTRA
void printParent (ListParent L); // ILHAM RIZKI HIDAYAT
void insertChild (ListChild &L); // MADE INDRAYANA PUTRA
void printChild (ListChild L); // ILHAM RIZKI HIDAYAT
void connect (ListParent &P, ListChild C, int IDP, int IDC); // MADE INDRAYANA PUTRA
bool checkConnection (ListParent P, ListChild C, int IDP, int IDC); // MADE INDRAYANA PUTRA
void disconnect (ListParent &P, ListChild C, int IDP, int IDC); // MADE INDRAYANA PUTRA
void printAll (ListParent P, ListChild C); // ILHAM RIZKI HIDAYAT
void printChildOfParent (ListParent P, ListChild C, int IDP); // ILHAM RIZKI HIDAYAT
void deleteChild (ListParent &P, ListChild &C); // MADE INDRAYANA PUTRA
void deleteParent (ListParent &P); // MADE INDRAYANA PUTRA
int totalFlight (ListParent P, ListChild C); // ILHAM RIZKI HIDAYAT
adrRelation biggestPromo (ListParent P, ListChild C, int IDP); // ILHAM RIZKI HIDAYAT

#endif // FLIGHT_H_INCLUDED
