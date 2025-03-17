#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

#include <string>
using namespace std;

class Employee {
private:
    int empNo;
    string name;
    double salary;
    string dept;

public:
    // Default constructor
    Employee();

    // Parameterized constructor
    Employee(int empNo, string name, double salary, string dept);

    // Function to accept employee details
    void Accept();

    // Function to display employee details
    void Display() const;

    // Getters for sorting
    int getEmpNo() const;
    string getName() const;
    double getSalary() const;
};

#endif