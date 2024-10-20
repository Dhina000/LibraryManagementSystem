#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

void addBook(stack<Book> &library, int id, string title, string author) {
    Book newBook;
    newBook.id = id;
    newBook.title = title;
    newBook.author = author;
    library.push(newBook);
    cout << "Book added: " << title << " by " << author << endl;
}

void issueBook(stack<Book> &library) {
    if (!library.empty()) {
        Book issuedBook = library.top();
        library.pop();
        cout << "Book issued: " << issuedBook.title << " by " << issuedBook.author << endl;
    } else {
        cout << "No books available to issue!" << endl;
    }
}

void returnBook(stack<Book> &library, int id, string title, string author) {
    addBook(library, id, title, author);
}

void viewTopBook(stack<Book> &library) {
    if (!library.empty()) {
        Book topBook = library.top();
        cout << "Top book is: " << topBook.title << " by " << topBook.author << endl;
    } else {
        cout << "No books in the library!" << endl;
    }
}

int main() {
    stack<Book> library;
    int choice;
    int id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a Book\n";
        cout << "2. Issue a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. View Top Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                addBook(library, id, title, author);
                break;
            case 2:
                issueBook(library);
                break;
            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                returnBook(library, id, title, author);
                break;
            case 4:
                viewTopBook(library);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
