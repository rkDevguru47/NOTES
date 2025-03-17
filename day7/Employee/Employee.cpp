#include "Employee.h"
#include <iostream>

using namespace std;

// Default constructor
Employee::Employee() : empNo(0), name(""), salary(0.0), dept("") {}

// Parameterized constructor
Employee::Employee(int empNo, string name, double salary, string dept)
    : empNo(empNo), name(name), salary(salary), dept(dept) {}

// Function to accept employee details
void Employee::Accept() {
    cout << "Enter Employee Number: ";
    cin >> empNo;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Salary: ";
    cin >> salary;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, dept);
}

// Function to display employee details
void Employee::Display() const {
    cout << "Employee Number: " << empNo << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
    cout << "Department: " << dept << endl;
}

// Getters for sorting
int Employee::getEmpNo() const {
    return empNo;
}

string Employee::getName() const {
    return name;
}

double Employee::getSalary() const {
    return salary;
}