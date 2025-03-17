#include <iostream>
#include <string>
using namespace std;

struct Product {
    string product_id;
    string name[50];
    string description[100];
    float price;
    int quantity;
    string category[50];
    string manufacturer[50];
};

// Function to print the details of a product
void DisplayProduct(Product product) {
    cout << "Product ID: " << product.product_id << endl;
    cout << "Name: " << product.name << endl;
    cout << "Description: " << product.description << endl;
    cout << "Price: $" << product.price << endl;
    cout << "Quantity: " << product.quantity << endl;
    cout << "Category: " << product.category << endl;
    cout << "Manufacturer: " << product.manufacturer << endl;
}

// Function to input the details of a product
void AcceptProduct(Product& product) {
    cout << "Enter product ID: ";
    if (!(cin >> product.product_id && product.product_id.length() == 10)) {
        cout << "Invalid input, please enter a valid product ID" << endl;
        return;
    }
    cout << "Enter product name: ";
    if (!(cin >> product.name && product.name.length() <= 50)) {
        cout << "Invalid input, please enter a valid product name" << endl;
        return;
    }
    cout << "Enter product description: ";
    if (!(cin >> product.description && product.description.length() <= 100)) {
        cout << "Invalid input, please enter a valid product description" << endl;
        return;
    }
    cout << "Enter product price: ";
    if (!(cin >> product.price && product.price >= 0)) {
        cout << "Invalid input, please enter a valid product price" << endl;
        return;
    }
    cout << "Enter product quantity: ";
    if (!(cin >> product.quantity && product.quantity >= 0)) {
        cout << "Invalid input, please enter a valid product quantity" << endl;
        return;
    }
    cout << "Enter product category: ";
    if (!(cin >> product.category && product.category.length() <= 50)) {
        cout << "Invalid input, please enter a valid product category" << endl;
        return;
    }
    cout << "Enter product manufacturer: ";
    if (!(cin >> product.manufacturer && product.manufacturer.length() <= 50)) {
        cout << "Invalid input, please enter a valid product manufacturer" << endl;
        return;
    }
}

int main() {
    Product product;
    AcceptProduct(product);
    DisplayProduct(product);
    return 0;
}
