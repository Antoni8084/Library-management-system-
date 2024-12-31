#include <iostream>
#include <string>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

    Book(int bookId, std::string bookTitle, std::string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};

int main() {
    std::cout << "Library Management System" << std::endl;
    return 0;
}