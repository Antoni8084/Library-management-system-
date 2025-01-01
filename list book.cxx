#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
    }
};

void showMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. List Books\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    vector<Book> books;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string title, author;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            int id = books.size() + 1;
            books.emplace_back(id, title, author);
            cout << "Book added successfully!\n";
            break;
        }
        case 2: {
            if (books.empty()) {
                cout << "No books available in the library.\n";
            } else {
                cout << "Book ID   Title                          Author\n";
                for (const auto &book : books) {
                    cout << book.id << "         " << book.title << "        " << book.author << endl;
                }
            }
            break;
        }
        case 3:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}