#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Employee
{
public:
    int empNo;
    string name;
    double salary;
    string dept;

    // Function to accept employee details
    void Accept()
    {
        cout << "Enter Employee Number: ";
        cin >> empNo;
        cout << "Enter Employee Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
        cout << "Enter Employee Department: ";
        cin.ignore(); 
        getline(cin, dept);
    }

    // Function to display employee details
    void Display() const
    {
        cout << "Employee Number: " << empNo << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
        cout << "Employee Department: " << dept << endl;
    }
};

// Function to sort employees by salary
bool compareBySalary(const Employee& a, const Employee& b)
{
    return a.salary < b.salary;
}

// Function to sort employees by name
bool compareByName(const Employee& a, const Employee& b)
{
    return a.name < b.name;
}

// Function to sort employees by empNo
bool compareByEmpNo(const Employee& a, const Employee& b)
{
    return a.empNo < b.empNo;
}

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].Accept();
    }

    // Display employee details
    cout << "\nEmployee Details:" << endl;
    for (int i = 0; i < n; i++)
    {
        employees[i].Display();
        cout << "------------------------" << endl;
    }

    // Sort by salary and display
    sort(employees, employees + n, compareBySalary);
    cout << "\nEmployees sorted by salary:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].Display();
        cout << "------------------------" << endl;
    }

    // Sort by name and display
    sort(employees, employees + n, compareByName);
    cout << "\nEmployees sorted by name:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].Display();
        cout << "------------------------" << endl;
    }

    // Sort by empNo and display
    sort(employees, employees + n, compareByEmpNo);
    cout << "\nEmployees sorted by employee number:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].Display();
        cout << "------------------------" << endl;
    }

    delete[] employees;
    return 0;
}