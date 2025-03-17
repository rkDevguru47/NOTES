#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class Product {
public:
    int id;
    string product_name;
    double price;

    Product(int id, string product_name, double price) 
    : id(id), product_name(product_name), price(price) {}
};

class Person {
public:
    string name;

    Person(string name) 
    : name(name) {}
};

class Customer : public Person {
public:
    string mobile;
    vector<Product> purchasedProducts;

    Customer(string name, string mobile) 
    : Person(name), mobile(mobile) {}

    void purchaseProduct(const Product& product) {
        purchasedProducts.push_back(product);
    }

    void displayPurchasedProducts() const {
        cout << "Products purchased by " << name << " (" << mobile << "):" << endl;
        for (vector<Product>::const_iterator it = purchasedProducts.begin(); it != purchasedProducts.end(); ++it) {
            cout << "Product ID: " << it->id << ", Name: " << it->product_name << ", Price: " << it->price << endl;
        }
    }
};

vector<Product> products;
vector<Customer> customers;

void displayAllProducts() {
    cout << "All Products:" << endl;
    for (vector<Product>::iterator it = products.begin(); it != products.end(); ++it) {
        cout << "Product ID: " << it->id << ", Name: " << it->product_name << ", Price: " << it->price << endl;
    }
}

void addNewProduct() {
    int id;
    string name;
    double price;
    cout << "Enter product ID: ";
    cin >> id;
    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;
    products.push_back(Product(id, name, price));
    cout << "Product added successfully!" << endl;
}

void addNewCustomer() {
    string name, mobile;
    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter customer mobile: ";
    cin >> mobile;
    customers.push_back(Customer(name, mobile));
    cout << "Customer added successfully!" << endl;
}

void customerPurchaseProduct() {
    string mobile;
    int productId;
    cout << "Enter customer mobile: ";
    cin >> mobile;
    cout << "Enter product ID to purchase: ";
    cin >> productId;

    vector<Customer>::iterator customerIt;
    for (customerIt = customers.begin(); customerIt != customers.end(); ++customerIt) {
        if (customerIt->mobile == mobile) {
            break;
        }
    }

    if (customerIt != customers.end()) {
        vector<Product>::iterator productIt;
        for (productIt = products.begin(); productIt != products.end(); ++productIt) {
            if (productIt->id == productId) {
                break;
            }
        }

        if (productIt != products.end()) {
            customerIt->purchaseProduct(*productIt);
            cout << "Product purchased successfully!" << endl;
        } else {
            cout << "Product not found!" << endl;
        }
    } else {
        cout << "Customer not found!" << endl;
    }
}

void displayCustomerPurchases() {
    string mobile;
    cout << "Enter customer mobile: ";
    cin >> mobile;

    vector<Customer>::iterator customerIt;
    for (customerIt = customers.begin(); customerIt != customers.end(); ++customerIt) {
        if (customerIt->mobile == mobile) {
            break;
        }
    }

    if (customerIt != customers.end()) {
        customerIt->displayPurchasedProducts();
    } else {
        cout << "Customer not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Display all products" << endl;
        cout << "2. New Customer" << endl;
        cout << "3. New Product" << endl;
        cout << "4. Customer purchase the product" << endl;
        cout << "5. Display products brought by specific customer" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllProducts();
                break;
            case 2:
                addNewCustomer();
                break;
            case 3:
                addNewProduct();
                break;
            case 4:
                customerPurchaseProduct();
                break;
            case 5:
                displayCustomerPurchases();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
