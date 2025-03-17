#include <iostream>
#include <algorithm>
#include "Employee.h"

using namespace std;

// Function to compare employees by salary
bool compareBySalary(const Employee &a, const Employee &b) {
    return a.getSalary() < b.getSalary();
}

// Function to compare employees by name
bool compareByName(const Employee &a, const Employee &b) {
    return a.getName() < b.getName();
}

// Function to compare employees by employee number
bool compareByEmpNo(const Employee &a, const Employee &b) {
    return a.getEmpNo() < b.getEmpNo();
}

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Sort by Salary\n";
        cout << "4. Sort by Name\n";
        cout << "5. Sort by Employee Number\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (employeeCount < MAX_EMPLOYEES) {
                    employees[employeeCount].Accept();
                    employeeCount++;
                } else {
                    cout << "Maximum employee limit reached." << endl;
                }
                break;
            }
            case 2: {
                for (int i = 0; i < employeeCount; i++) {
                    employees[i].Display();
                    cout << endl;
                }
                break;
            }
            case 3: {
                sort(employees, employees + employeeCount, compareBySalary);
                cout << "Employees sorted by salary." << endl;
                break;
            }
            case 4: {
                sort(employees, employees + employeeCount, compareByName);
                cout << "Employees sorted by name." << endl;
                break;
            }
            case 5: {
                sort(employees, employees + employeeCount, compareByEmpNo);
                cout << "Employees sorted by employee number." << endl;
                break;
            }
            case 6: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 6);

    return 0;
}