#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};

void showMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. List Books\n";
    cout << "3. Issue Book\n";
    cout << "4. Return Book\n";
     cout << "5. Search Book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Book> books = {
        Book(1, "1984", "George Orwell"),
        Book(2, "To Kill a Mockingbird", "Harper Lee"),
        Book(3, "The Great Gatsby", "F. Scott Fitzgerald"),
        Book(4, "Pride and Prejudice", "Jane Austen"),
        Book(5, "Moby-Dick", "Herman Melville")
  
    };

    int choice;
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
                cout << "Book ID   Title                          Author               Status\n";
                for (const auto &book : books) {
                    cout << book.id << "         " << book.title << "        "
                         << book.author << "        "
                         << (book.isIssued ? "Issued" : "Available") << endl;
                }
            }
            break;
        }
        case 3: {
            if (books.empty()) {
                cout << "No books available to issue.\n";
            } else {
                int bookId;
                cout << "Enter the book ID to issue: ";
                cin >> bookId;
                bool found = false;
                for (auto &book : books) {
                    if (book.id == bookId) {
                        if (book.isIssued) {
                            cout << "Book '" << book.title << "' is already issued.\n";
                        } else {
                            book.isIssued = true;
                            cout << "Book '" << book.title << "' issued successfully!\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found.\n";
                }
            }
            break;
        }
        case 4: {
            if (books.empty()) {
                cout << "No books available in the library.\n";
            } else {
                int bookId;
                cout << "Enter the book ID to return: ";
                cin >> bookId;
                bool found = false;
                for (auto &book : books) {
                    if (book.id == bookId) {
                        if (book.isIssued) {
                            book.isIssued = false;
                            cout << "Book '" << book.title << "' returned successfully!\n";
                        } else {
                            cout << "Book '" << book.title << "' was not issued.\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found.\n";
                }
            }
            break;
        }
        
        case 5: { // Search feature added here
    if (books.empty()) {
        cout << "No books available in the library.\n";
    } else {
        string keyword;
        cout << "Enter book title or author to search: ";
        cin.ignore();
        getline(cin, keyword);
        bool found = false;
        for (const auto &book : books) {
            if (book.title.find(keyword) != string::npos || 
                book.author.find(keyword) != string::npos) {
                cout << "Found: ID " << book.id << ", Title: " << book.title 
                     << ", Author: " << book.author 
                     << ", Status: " << (book.isIssued ? "Issued" : "Available") << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching the keyword.\n";
        }
    }
    break;
}
        
        case 6:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}