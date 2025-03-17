#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include this header for find_if

using namespace std;

class Product {
public:
    int id;
    string product_name;
    double price;

    Product(int id, string product_name, double price) : id(id), product_name(product_name), price(price) {}
};

class Person {
public:
    string name;

    Person(string name) : name(name) {}
};

class Customer : public Person {
public:
    string mobile;
    vector<Product> purchasedProducts;

    Customer(string name, string mobile) : Person(name), mobile(mobile) {}

    void purchaseProduct(const Product& product) {
        purchasedProducts.push_back(product);
    }

    void displayPurchasedProducts() const {
        cout << "Products purchased by " << name << " (" << mobile << "):" << endl;
        for (const auto& product : purchasedProducts) {
            cout << "Product ID: " << product.id << ", Name: " << product.product_name << ", Price: " << product.price << endl;
        }
    }
};

vector<Product> products;
vector<Customer> customers;

void displayAllProducts() {
    cout << "All Products:" << endl;
    for (const auto& product : products) {
        cout << "Product ID: " << product.id << ", Name: " << product.product_name << ", Price: " << product.price << endl;
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
    products.emplace_back(id, name, price);
    cout << "Product added successfully!" << endl;
}

void addNewCustomer() {
    string name, mobile;
    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter customer mobile: ";
    cin >> mobile;
    customers.emplace_back(name, mobile);
    cout << "Customer added successfully!" << endl;
}

void customerPurchaseProduct() {
    string mobile;
    int productId;
    cout << "Enter customer mobile: ";
    cin >> mobile;
    cout << "Enter product ID to purchase: ";
    cin >> productId;

    auto customerIt = find_if(customers.begin(), customers.end(), [&mobile](const Customer& customer) {
        return customer.mobile == mobile;
    });

    if (customerIt != customers.end()) {
        auto productIt = find_if(products.begin(), products.end(), [productId](const Product& product) {
            return product.id == productId;
        });

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

    auto customerIt = find_if(customers.begin(), customers.end(), [&mobile](const Customer& customer) {
        return customer.mobile == mobile;
    });

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