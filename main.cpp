#include <iostream>
#include "flight.h"
#include "child.h"
#include "parent.h"
#include "relation.h"

using namespace std;
adrChild C;
adrParent P;
adrRelation R;

int main()
{
    cout << "Welcome to Bojongsoang International Airport!" << endl;

    ListChild L1;
    createListCh(L1);
    cout << "ID 3 Singapore Airlines 10%" << endl;
    insertChild(L1);
    cout << "ID 9 Garuda Indonesia 5%" << endl;
    insertChild(L1);
    cout << "ID 88 KLM 50%" << endl;
    insertChild(L1);
    cout << "ID 77 Emirates 60%" << endl;
    insertChild(L1);
    printChild(L1);

    cout << endl;
    ListParent L2;
    createListPar(L2);
    cout << "ID 22 Tuj TOKYO" << endl;
    insertParent(L2);
    cout << "ID 99 Tuj LONDON" << endl;
    insertParent(L2);
    cout << "ID 45 Tuj JAKARTA" << endl;
    insertParent(L2);
    cout << "ID 100 Tuj BALI" << endl;
    insertParent(L2);
    cout << "ID 100 Tuj BALI" << endl;
    insertParent(L2);
    printParent(L2);

    connect(L2,L1,99,9);
    connect(L2,L1,22,77);
    connect(L2,L1,100,77);
    connect(L2,L1,100,9);
    connect(L2,L1,99,3);
    connect(L2,L1,45,3);
    connect(L2,L1,99,77);
    connect(L2,L1,99,88);
    connect(L2,L1,1,1);
    printChildOfParent(L2,L1,99);
    printChildOfParent(L2,L1,45);

    cout << "Apakah ke London bisa dengan Garuda Indonesia?" << endl;
    cout << checkConnection(L2,L1,99,9) << endl;
    cout << endl;

    cout << "Maskapai dengan promo terbesar ke London : " << endl;
    cout << maskapai(child(biggestPromo(L2,L1,99))) << " dengan diskon sebesar " << diskon(child(biggestPromo(L2,L1,99))) << "%" << endl;
    cout << endl;

    cout << "Hapus Child : ";
    deleteChild(L2,L1);
    printChild(L1);
    printChildOfParent(L2,L1,99);
    cout << endl;

    cout << "Hapus Parent : ";
    deleteParent(L2);
    printParent(L2);
    printAll(L2,L1);
    cout << endl;

    cout << "Jumlah Rute Semua Maskapai : " << totalFlight(L2,L1) << " rute" << endl;
    //insertRel(child(P), R);
    /// :o
    return 0;
}
