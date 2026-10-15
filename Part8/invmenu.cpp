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



void invMenu()
{
    int menuChoice = 0;
    while (true) {

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

        if(menuChoice < 1 || menuChoice > 5)
        {
            
            cout << "\nPlease enter a number in the range 1 - 5\n";
        }
    } while(menuChoice < 1 || menuChoice > 5);

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
            return;
    }
    }
}

void lookUpBook()
{
    cout << "\nWhat is the title of the book you would like to look up? ";
    string title; 
    cin.ignore();
    getline(cin, title);

    for(int i = 0; i < SIZE; i++) {
        if(bookTitle[i] == title) {
            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
            break;
        }
    }
    cout << "\nBook Not Found\n";
}

void addBook()
{
    cout << "You've selected 'Add Book.'";
    bool flag = false;
    int index = 0;
    for(index = 0; index < SIZE; index++)
    {
        if(bookTitle[index].empty())
        {
            flag = true;
            break;
        }
    }
    if(flag){
        string titleInput;
        string isbnInput;
        string authorInput;
        string publisherInput;
        string dateAddedInput;
        int qtyOnHandInput;
        double wholesaleInput;
        double retailInput;
        
        cout << "Enter your information for the new book:\n";
        cout << "Title: ";
        cin.ignore();
        getline(cin, titleInput);
        cout << "ISBN: ";
        getline(cin, isbnInput);
        cout << "Author: ";
        getline(cin, authorInput);
        cout << "Publisher: ";
        getline(cin, publisherInput);
        cout << "Date Added (mm/dd/yyyy): ";
        getline(cin, dateAddedInput);
        cout << "Quantity on Hand: ";
        cin >> qtyOnHandInput;
        cout << "Wholesale Cost: ";
        cin >> wholesaleInput;
        cout << "Retail Price: ";
        cin >> retailInput;
        bookTitle[index] = titleInput;
        isbn[index] = isbnInput;
        author[index] = authorInput;
        publisher[index] = publisherInput;
        dateAdded[index] = dateAddedInput;
        qtyOnHand[index] = qtyOnHandInput;
        wholesale[index] = wholesaleInput;
        retail[index] = retailInput;

        bookInfo(titleInput, isbnInput, authorInput, publisherInput, dateAddedInput, qtyOnHandInput, wholesaleInput, retailInput);
        cout << endl;
    }
    else{
        cout << "Sorry, our inventory is full at this time!" << endl;
    }
}

void editBook()
{
    string title;
    cout << "\nWhat is the title of the book you would like to edit? ";
    cin.ignore();
    getline(cin, title);

    int index = -1;
    for (int i = 0; i < SIZE; i++) {
        if (bookTitle[i] == title) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "This book is not in our inventory." << endl;
        return;
    }

    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);

    int choice = 0;
    do {
        cout << "\nWhich field would you like to edit?\n";
        cout << "1. Title\n";
        cout << "2. ISBN\n";
        cout << "3. Author\n";
        cout << "4. Publisher\n";
        cout << "5. Date Added\n";
        cout << "6. Quantity on Hand\n";
        cout << "7. Wholesale Cost\n";
        cout << "8. Retail Price\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while(choice < 1 || choice > 9) {
            cout << "Please enter a number in the range 1 - 9: ";
            cin >> choice;
        }

        switch(choice) {
            case 1:
                cout << "Enter new title: ";
                cin.ignore();
                getline(cin, bookTitle[index]);
                break;
            case 2:
                cout << "Enter new ISBN: ";
                cin.ignore();
                getline(cin, isbn[index]);
                break;
            case 3:
                cout << "Enter new author: ";
                cin.ignore();
                getline(cin, author[index]);
                break;
            case 4:
                cout << "Enter new publisher: ";
                cin.ignore();
                getline(cin, publisher[index]);
                break;
            case 5:
                cout << "Enter new date added: ";
                cin.ignore();
                getline(cin, dateAdded[index]);
                break;
            case 6:
                cout << "Enter new quantity on hand: ";
                cin >> qtyOnHand[index];
                break;
            case 7:
                cout << "Enter new wholesale cost: ";
                cin >> wholesale[index];
                break;
            case 8:
                cout << "Enter new retail price: ";
                cin >> retail[index];
                break;
            case 9:
                break;
            default:
                cout << "Please enter a number in the range 1 - 9.\n";
        }
    }
    while(choice != 9);
}

void deleteBook()
{
    string title;
    cout << "\nYou selected Delete a Book\n";
    cin.ignore();
    getline(cin, title);
    int index = -1;
    for (int i = 0; i < SIZE; i++) {
        if (bookTitle[i] == title) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "This book is not in our inventory." << endl;
        
    }
    else {

    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);

    string answer;
    cout << "\nDelete this book? (Y/N): ";
    cin >> answer;
    cin.ignore();

    if(answer == "Y" || answer == "y")
    {
        bookTitle[index] = "";
        isbn[index] = "";
        author[index] = "";
        publisher[index] = "";
        dateAdded[index] = "";
        qtyOnHand[index] = 0;
        wholesale[index] = 0.0;
        retail[index] = 0.0;
        cout << "\nBook Deleted\n";
    }
}
}
