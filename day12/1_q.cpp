#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int id;
public:
    Employee() : name(""), id(0) {}
    Employee(string name, int id) : name(name), id(id) {}
    string getName() const { return name; }
    int getId() const { return id; }

    // Overload the < operator for comparison
    bool operator<(const Employee& other) const {
        return id < other.id;
    }
};

int main() {
    // Vector
    vector<Employee> employees;
    employees.emplace_back("John Doe", 1);
    employees.emplace_back("Jane Smith", 2);
    employees.emplace_back("Bob Johnson", 3);

    cout << "Vector of Employees:" << endl;
    for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it) {
        cout << "Name: " << it->getName() << ", ID: " << it->getId() << endl;
    }

    // Stack
    stack<Employee> employeeStack;
    employeeStack.push(employees[0]);
    employeeStack.push(employees[1]);
    employeeStack.push(employees[2]);

    cout << "\nStack of Employees:" << endl;
    while (!employeeStack.empty()) {
        const Employee& employee = employeeStack.top();
        cout << "Name: " << employee.getName() << ", ID: " << employee.getId() << endl;
        employeeStack.pop();
    }

    // List
    list<Employee> employeeList;
    employeeList.emplace_back("Alice Brown", 4);
    employeeList.emplace_back("Tom Wilson", 5);
    employeeList.emplace_back("Sarah Davis", 6);

    cout << "\nList of Employees:" << endl;
    for (list<Employee>::iterator it = employeeList.begin(); it != employeeList.end(); ++it) {
        cout << "Name: " << it->getName() << ", ID: " << it->getId() << endl;
    }

    // Set
    set<Employee> employeeSet;
    employeeSet.emplace("David Lee", 7);
    employeeSet.emplace("Emily Chen", 8);
    employeeSet.emplace("Michael Wang", 9);

    cout << "\nSet of Employees:" << endl;
    for (set<Employee>::iterator it = employeeSet.begin(); it != employeeSet.end(); ++it) {
        cout << "Name: " << it->getName() << ", ID: " << it->getId() << endl;
    }

    // Map
    map<int, Employee> employeeMap;
    employeeMap[1] = employees[0];
    employeeMap[2] = employees[1];
    employeeMap[3] = employees[2];

    cout << "\nMap of Employees:" << endl;
    for (map<int, Employee>::iterator it = employeeMap.begin(); it != employeeMap.end(); ++it) {
        cout << "ID: " << it->first << ", Name: " << it->second.getName() << ", ID: " << it->second.getId() << endl;
    }

    return 0;
}