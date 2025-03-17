#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class MobilePhone {
private:
    string serialNo;
    string modelNo;
    string brandName;
    double price;
public:
    // Default constructor
    MobilePhone() : serialNo(""), modelNo(""), brandName(""), price(0.0) {}

    // Parameterized constructor
    MobilePhone(string serialNo, string modelNo, string brandName, double price): 
    serialNo(serialNo), modelNo(modelNo), brandName(brandName), price(price) {}

    string getSerialNo() const { return serialNo; }
    string getModelNo() const { return modelNo; }
    string getBrandName() const { return brandName; }
    double getPrice() const { return price; }
};

bool compareByPrice(const MobilePhone& a, const MobilePhone& b) {
    return a.getPrice() < b.getPrice();
}

int main() {
    const int MAX_PHONES = 100;
    MobilePhone phones[MAX_PHONES];
    int phoneCount = 0;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add/write MobilePhone to file" << endl;
        cout << "2. Read all Mobile phones from file and store them in an array" << endl;
        cout << "3. Read all Mobile phones from file and store them in an array and display sorted by price" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (phoneCount >= MAX_PHONES) {
                cout << "Array is full. Cannot add more phones." << endl;
                break;
            }

            string serialNo, modelNo, brandName;
            double price;

            cout << "Enter serial number: ";
            cin >> serialNo;
            cout << "Enter model number: ";
            cin >> modelNo;
            cout << "Enter brand name: ";
            cin >> brandName;
            cout << "Enter price: ";
            cin >> price;

            MobilePhone phone(serialNo, modelNo, brandName, price);
            phones[phoneCount++] = phone;

            ofstream fout("phones.txt", ios::app);
            fout << serialNo << "," << modelNo << "," << brandName << "," << price << endl;
            fout.close();

            cout << "Mobile phone added to the file." << endl;
            break;
        }
        case 2: {
            ifstream fin("phones.txt");
            string line;
            phoneCount = 0;
            while (getline(fin, line) && phoneCount < MAX_PHONES) {
                size_t pos = line.find(",");
                string serialNo = line.substr(0, pos);
                line = line.substr(pos + 1);

                pos = line.find(",");
                string modelNo = line.substr(0, pos);
                line = line.substr(pos + 1);

                pos = line.find(",");
                string brandName = line.substr(0, pos);
                double price = stod(line.substr(pos + 1));

                MobilePhone phone(serialNo, modelNo, brandName, price);
                phones[phoneCount++] = phone;
            }
            fin.close();

            cout << "Mobile phones read from the file and stored in an array." << endl;
            break;
        }
        case 3: {
            ifstream fin("phones.txt");
            string line;
            phoneCount = 0;
            while (getline(fin, line) && phoneCount < MAX_PHONES) {
                size_t pos = line.find(",");
                string serialNo = line.substr(0, pos);
                line = line.substr(pos + 1);

                pos = line.find(",");
                string modelNo = line.substr(0, pos);
                line = line.substr(pos + 1);

                pos = line.find(",");
                string brandName = line.substr(0, pos);
                double price = stod(line.substr(pos + 1));

                MobilePhone phone(serialNo, modelNo, brandName, price);
                phones[phoneCount++] = phone;
            }
            fin.close();

            sort(phones, phones + phoneCount, compareByPrice);

            cout << "Mobile phones read from the file, stored in an array, and displayed sorted by price:" << endl;
            for (int i = 0; i < phoneCount; ++i) {
                cout << "Serial No: " << phones[i].getSerialNo() << ", Model No: " << phones[i].getModelNo() << ", Brand Name: " << phones[i].getBrandName() << ", Price: " << phones[i].getPrice() << endl;
            }
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}