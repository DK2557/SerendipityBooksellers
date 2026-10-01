#include "bookinfo.h"
#include <iostream>
#include <string>
using namespace std;

void bookInfo(string isbn, string title, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail)
{
    cout << "Serendipity Booksellers\n";
    cout << "    Book Information\n\n";
    cout << "ISBN: " << isbn << "\n";
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Publisher: " << publisher << "\n";
    cout << "Date Added: " << dateAdded << "\n";
    cout << "Quantity-On-Hand: " << qtyOnHand << "\n";
    cout << "Wholesale Cost: " << wholesale << "\n";
    cout << "Retail Price: " << retail << "\n";
}
