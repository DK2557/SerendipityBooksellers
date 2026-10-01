#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int SIZE = 20;

extern string bookTitle[SIZE];
extern string isbn[SIZE];
extern string author[SIZE];
extern string publisher[SIZE];
extern string dateAdded[SIZE];
extern int qtyOnHand[SIZE];
extern double wholesale[SIZE];
extern double retail[SIZE];

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void readText(string prompt, string &value)
{
    cout << prompt;
    getline(cin, value);
}

int findBook(const string &title)
{
    for(int index = 0; index < SIZE; index++)
    {
        if(bookTitle[index] == title)
        {
            return index;
        }
    }
    return -1;
}

void invMenu()
{
    int menuChoice = 0;

    do
    {
        cout << "Serendipity Booksellers\n";
        cout << "  Inventory Database\n";
        cout << "\n1. Look Up a Book\n";
        cout << "2. Add a Book\n";
        cout << "3. Edit a Book's Record\n";
        cout << "4. Delete a Book\n";
        cout << "5. Return to the Main Menu\n";
        cout << "\nEnter Your Choice: ";

        if(!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 5)
        {
            clearInput();
            cout << "\nPlease enter a number in the range 1 - 5\n";
        }
    } while(menuChoice < 1 || menuChoice > 5 || cin.fail());

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(menuChoice)
    {
        case 1:
            lookUpBook();
            break;
        case 2:
            addBook();
            break;
        case 3:
            editBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            cout << "\nReturning to Main Menu\n";
            break;
    }
}

void lookUpBook()
{
    string title;
    cout << "You selected Look Up a Book\n\n";
    readText("Enter the Title of the Book: ", title);

    int index = findBook(title);
    if(index < 0)
    {
        cout << "\nBook Not Found\n";
        return;
    }

    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);
}

void addBook()
{
    cout << "\nYou selected Add a Book\n";

    int index = -1;
    for(int i = 0; i < SIZE; i++)
    {
        if(bookTitle[i].empty())
        {
            index = i;
            break;
        }
    }

    if(index < 0)
    {
        cout << "\nThe inventory is full.\n";
        return;
    }

    readText("\nEnter the Title: ", bookTitle[index]);
    readText("\nEnter the ISBN: ", isbn[index]);
    readText("\nEnter the Author: ", author[index]);
    readText("\nEnter the Publisher: ", publisher[index]);
    readText("\nEnter the Date Added: ", dateAdded[index]);

    cout << "\nEnter the Quantity of the Book: ";
    while(!(cin >> qtyOnHand[index]) || qtyOnHand[index] < 0)
    {
        clearInput();
        cout << "Enter the Quantity of the Book: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter the Wholesale Cost: ";
    while(!(cin >> wholesale[index]) || wholesale[index] < 0)
    {
        clearInput();
        cout << "Enter the Wholesale Cost: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter the Retail Price: ";
    while(!(cin >> retail[index]) || retail[index] < 0)
    {
        clearInput();
        cout << "Enter the Retail Price: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void editBook()
{
    string title;
    cout << "\nYou selected Edit a Book's Record\n";
    readText("\nEnter the Title of the Book: ", title);

    int index = findBook(title);
    if(index < 0)
    {
        cout << "\nBook Not Found\n";
        return;
    }

    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);

    int field = 0;
    do
    {
        cout << "\n1. Edit ISBN\n";
        cout << "2. Edit Title\n";
        cout << "3. Edit Author\n";
        cout << "4. Edit Publisher\n";
        cout << "5. Edit Date\n";
        cout << "6. Edit Quantity\n";
        cout << "7. Edit Wholesale Cost\n";
        cout << "8. Edit Retail Price\n";
        cout << "\nEnter Your Choice: ";

        if(!(cin >> field) || field < 1 || field > 8)
        {
            clearInput();
            cout << "\nPlease enter a number in the range 1 - 8\n";
        }
    } while(field < 1 || field > 8 || cin.fail());

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(field)
    {
        case 1:
            readText("\nEnter the new ISBN: ", isbn[index]);
            break;
        case 2:
            readText("\nEnter the new Title: ", bookTitle[index]);
            break;
        case 3:
            readText("\nEnter the new Author: ", author[index]);
            break;
        case 4:
            readText("\nEnter the new Publisher: ", publisher[index]);
            break;
        case 5:
            readText("\nEnter the new Date: ", dateAdded[index]);
            break;
        case 6:
            cout << "\nEnter the new Quantity: ";
            while(!(cin >> qtyOnHand[index]) || qtyOnHand[index] < 0)
            {
                clearInput();
                cout << "Enter the new Quantity: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 7:
            cout << "\nEnter the new Wholesale Cost: ";
            while(!(cin >> wholesale[index]) || wholesale[index] < 0)
            {
                clearInput();
                cout << "Enter the new Wholesale Cost: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 8:
            cout << "\nEnter the new Retail Price: ";
            while(!(cin >> retail[index]) || retail[index] < 0)
            {
                clearInput();
                cout << "Enter the new Retail Price: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
    }
}

void deleteBook()
{
    string title;
    cout << "\nYou selected Delete a Book\n";
    readText("\nEnter the Title of the Book: ", title);

    int index = findBook(title);
    if(index < 0)
    {
        cout << "\nBook Not Found\n";
        return;
    }

    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);

    char answer;
    cout << "\nDelete this book? (Y/N): ";
    cin >> answer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(answer == 'Y' || answer == 'y')
    {
        bookTitle[index].clear();
        isbn[index].clear();
        author[index].clear();
        publisher[index].clear();
        dateAdded[index].clear();
        qtyOnHand[index] = 0;
        wholesale[index] = 0.0;
        retail[index] = 0.0;
        cout << "\nBook Deleted\n";
    }
}
