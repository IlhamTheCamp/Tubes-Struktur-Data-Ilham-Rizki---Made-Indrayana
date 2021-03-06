#include <iostream>
#include "flight.h"
#include "child.h"
#include "parent.h"
#include "relation.h"

using namespace std;

ListParent Destination;
ListChild Airlines;
adrChild C;
adrParent P;
adrRelation R;

void menu();
void displayMenu();
void runMenu (int menu);

int main()
{
    createListPar(Destination);
    createListCh(Airlines);
    menu();
    return 0;
}

void menu()
{
    int option;
    do {
        displayMenu();
        cin >> option;
        runMenu(option);
    } while (option!=0);
}

void displayMenu()
{
    cout << "=============================================" << endl;
    cout << "Welcome to Bojongsoang International Airport!" << endl;
    cout << "=============================================" << endl;
    cout << "1.  Insert Airlines" << endl;
    cout << "2.  View All Available Airlines" << endl;
    cout << "3.  Insert Destination" << endl;
    cout << "4.  View All Available Destination" << endl;
    cout << "5.  Make A Route" << endl;
    cout << "6.  View All Route" << endl;
    cout << "7.  Delete Route" << endl;
    cout << "8.  Delete Airlines" << endl;
    cout << "9.  Delete Destination" << endl;
    cout << "10. Count Total Available Flight Route" << endl;
    cout << "11. View Route With The Biggest Discount" << endl;
    cout << "12. View Airlines By Routes" << endl;
    cout << "0.  Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Option : ";
}

void runMenu (int menu)
{
    system("CLS");
    switch (menu) {
    case 1 :
        cout << "=============================================" << endl;
        cout << "Please Insert Airlines ID, Name, and Discount" << endl;
        cout << "=============================================" << endl;
        insertChild(Airlines);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 2 :
        cout << "=============================================" << endl;
        cout << "                  Airlines" << endl;
        cout << "=============================================" << endl;
        printChild(Airlines);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 3 :
        cout << "=============================================" << endl;
        cout << "   Please Insert Destination ID and Name" << endl;
        cout << "=============================================" << endl;
        insertParent(Destination);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 4 :
        cout << "=============================================" << endl;
        cout << "                Destinations" << endl;
        cout << "=============================================" << endl;
        printParent(Destination);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 5 :
        cout << "=============================================" << endl;
        cout << "  Please Insert Airlines and Destination ID" << endl;
        cout << "=============================================" << endl;
        int addIDP, addIDC;
        cout << "ID Airlines    : ";
        cin >> addIDC;
        cout << "ID Destination : ";
        cin >> addIDP;
        connect(Destination, Airlines, addIDP, addIDC);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 6 :
        cout << "=============================================" << endl;
        cout << "                   Routes" << endl;
        cout << "=============================================" << endl;
        printAll(Destination, Airlines);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 7 :
        cout << "=============================================" << endl;
        cout << "  Please Insert Airlines and Destination ID" << endl;
        cout << "=============================================" << endl;
        int delIDP, delIDC;
        cout << "ID Airlines    : ";
        cin >> delIDC;
        cout << "ID Destination : ";
        cin >> delIDP;
        disconnect(Destination, Airlines, delIDP, delIDC);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 8 :
        cout << "=============================================" << endl;
        cout << "           Please Insert Airlines ID" << endl;
        cout << "=============================================" << endl;
        deleteChild(Destination, Airlines);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 9 :
        cout << "=============================================" << endl;
        cout << "         Please Insert Destination ID" << endl;
        cout << "=============================================" << endl;
        deleteParent(Destination);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 10 :
        cout << "=============================================" << endl;
        cout << "               Route Count" << endl;
        cout << "=============================================" << endl;
        cout << "Total Available Flight Route(s) : " << totalFlight(Destination, Airlines) << " route(s)" << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 11 :
        cout << "=============================================" << endl;
        cout << "         Please Insert Destination ID" << endl;
        cout << "=============================================" << endl;
        int IDP;
        cout << "ID : ";
        cin >> IDP;
        P = searchParent(Destination, IDP);
        if (P==NULL) {
            cout << "Destination Doesn't Exist!" << endl;
        } else if (firstRelation(childList(P))==NULL) {
            cout << "No Routes Exist in That Destination!" << endl;
        } else {
            adrRelation Route = biggestPromo(Destination, Airlines, IDP);
            cout << "Airlines With The Biggest Discount is :" << endl;
            cout << IDChild(child(Route)) << " " << maskapai(child(Route)) << " With a Discount of " << diskon(child(Route)) << " %" << endl;
        }
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 12 :
        cout << "=============================================" << endl;
        cout << "         Please Insert Destination ID" << endl;
        cout << "=============================================" << endl;
        int IDPar;
        cout << "ID : ";
        cin >> IDPar;
        printChildOfParent(Destination, Airlines, IDPar);
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 0 :
        break;
    default :
        cout << "=============================================" << endl;
        cout << "                     OOPS!" << endl;
        cout << "=============================================" << endl;
        cout << "                  Wrong Input" << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    }
    system("CLS");
}
