#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Emp {
public:
    int eid;
    string name;
    string address;
    double salary;

    Emp(int id, string n, string a, double s) {
        eid = id;
        name = n;
        address = a;
        salary = s;
    }
};

vector<Emp> employees;

void addRecord() {
    int id;
    string name, address;
    double salary;

    cout << "Enter employee ID: ";
    cin >> id;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter employee address: ";
    getline(cin, address);
    cout << "Enter employee salary: ";
    cin >> salary;

    employees.emplace_back(id, name, address, salary);
    cout << "Record added successfully!" << endl;
}

void displayAll() {
    if (employees.empty()) {
        cout << "No records found." << endl;
        return;
    }

    cout << "Employee Records:" << endl;
    for (const auto& emp : employees) {
        cout << "ID: " << emp.eid << ", Name: " << emp.name << ", Address: " << emp.address << ", Salary: " << emp.salary << endl;
    }
}

void searchRecord() {
    int id;
    cout << "Enter employee ID to search: ";
    cin >> id;

    auto it = find_if(employees.begin(), employees.end(), [id](const Emp& emp) { return emp.eid == id; });
    if (it != employees.end()) {
        cout << "ID: " << it->eid << ", Name: " << it->name << ", Address: " << it->address << ", Salary: " << it->salary << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

void deleteRecord() {
    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;

    auto it = find_if(employees.begin(), employees.end(), [id](const Emp& emp) { return emp.eid == id; });
    if (it != employees.end()) {
        employees.erase(it);
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

void modifyRecord() {
    int id;
    cout << "Enter employee ID to modify: ";
    cin >> id;

    auto it = find_if(employees.begin(), employees.end(), [id](const Emp& emp) { return emp.eid == id; });
    if (it != employees.end()) {
        string name, address;
        double salary;

        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter new address: ";
        getline(cin, address);
        cout << "Enter new salary: ";
        cin >> salary;

        it->name = name;
        it->address = address;
        it->salary = salary;
        cout << "Record modified successfully!" << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nEmployee Management System" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Modify" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                modifyRecord();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
