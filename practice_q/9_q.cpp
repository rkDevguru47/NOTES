#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    double price;

public:
    Book(int id, string t, string a, double p) {
        bookId = id;
        title = t;
        author = a;
        price = p;
    }

    int getBookId() {
        return bookId;
    }

    void display() {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: Rs. " << price << endl;
    }
};

void addBook() {
    ofstream file("books.dat", ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    int id;
    string title, author;
    double price;

    cout << "Enter Book ID: ";
    cin >> id;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Book Author: ";
    getline(cin, author);
    cout << "Enter Book Price: ";
    cin >> price;

    Book book(id, title, author, price);
    file.write(reinterpret_cast<char*>(&book), sizeof(Book));
    file.close();
    cout << "Book added successfully." << endl;
}

void displayAll() {
    ifstream file("books.dat", ios::binary);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Book book(0, "", "", 0.0);
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        book.display();
        cout << endl;
    }
    file.close();
}

void displaySpecific(int pos) {
    ifstream file("books.dat", ios::binary);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    file.seekg(pos * sizeof(Book), ios::beg);
    Book book(0, "", "", 0.0);
    file.read(reinterpret_cast<char*>(&book), sizeof(Book));
    book.display();
    file.close();
}

void deleteBook(int id) {
    ifstream inFile("books.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cout << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    Book book(0, "", "", 0.0);
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.getBookId() != id) {
            tempFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("books.dat");
        rename("temp.dat", "books.dat");
        cout << "Book deleted successfully." << endl;
    } else {
        remove("temp.dat");
        cout << "Book not found." << endl;
    }
}

int main() {
    int choice, pos, id;
    while (true) {
        cout << "\nBook Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Display Specific" << endl;
        cout << "4. Delete Book" << endl;
        cout << "5. Exit" << endl;  
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                cout << "Enter the position of the book to display: ";
                cin >> pos;
                displaySpecific(pos);
                break;
            case 4:
                cout << "Enter the book ID to delete: ";
                cin >> id;
                deleteBook(id);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
