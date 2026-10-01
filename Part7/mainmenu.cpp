#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookinfo.h"
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;

string bookTitle[SIZE];
string isbn[SIZE];
string author[SIZE];
string publisher[SIZE];
string dateAdded[SIZE];
int qtyOnHand[SIZE];
double wholesale[SIZE];
double retail[SIZE];

int main()
{
    int selection = 0;

    do
    {
        cout << "Serendipity Booksellers\n";
        cout << "\tMain Menu\n";
        cout << "\n1. Cashier Module\n";
        cout << "2. Inventory Database Module\n";
        cout << "3. Report Module\n";
        cout << "4. Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> selection;

        if(selection < 1 || selection > 4)
        {
            cout << "\nPlease enter a number in the range 1 - 4\n";
        }
    } while(selection < 1 || selection > 4);

    switch(selection)
    {
        case 1:
            cin.ignore();
            cashier();
            break;
        case 2:
            invMenu();
            break;
        case 3:
            reports();
            break;
        case 4:
            cout << "\nThank You for Using Serendipity Booksellers\n";
            break;
    }

    return 0;
}
