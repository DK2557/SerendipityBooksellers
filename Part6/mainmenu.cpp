#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookinfo.h"
#include <iostream>
using namespace std;
int main()
{
    int number;
    do
    {
        cout << " Serendipity Booksellers\n \tMain Menu\n";
        cout << "\n1. Cashier Module";
        cout << "\n2. Inventory Database Module";
        cout << "\n3. Report Module";
        cout << "\n4. Exit\n";
        cout << "\n Enter Your Choice: ";
        cin >> number;
        while (number < 1 || number > 4)
        {
            cout << "Please enter a number in the range 1 - 4.\n";
            cout << "Enter Your Choice: ";
            cin >> number;
        }
        switch (number)
        {
            case 1: cin.ignore(); cashier(); break;
            case 2: invMenu(); break;
            case 3: reports(); break;
            case 4: cout << "You selected item 4.\n"; break;
        }
    } while (number != 4);
    return 0;
}
