#include <iostream>

using namespace std;

class Employee 
{
protected:
    int eid;
    string name;
    double salary;

public:
    Employee(): eid(0), name(""), salary(0) {}
    Employee(int eid, string name, double salary) 
    {
        this->eid = eid;
        this->name = name;
        this->salary = salary;
    }

    virtual double calcSalary() = 0;
    virtual void accept(double value) = 0;

    virtual void display() 
    {
        cout << "Employee ID: " << eid << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

};

class PermEmployee : public Employee
{
private:
    double ta;
    double hra;

public:
    PermEmployee(int eid, string name, double salary, double ta, double hra) : Employee(eid, name, salary) 
    {
        this->ta = ta;
        this->hra = hra;
    }

    double calcSalary() override 
    {
        return salary + ta + hra;
    }
    void accept(double value) override 
    {
        ta = value;
        hra = value;
    }
};

class ContractEmployee : public Employee 
{
private:
    double hrs;
    double rate;

public:
    ContractEmployee(int eid, string name, double salary, double hrs, double rate) : Employee(eid, name, salary) 
    {
        this->hrs = hrs;
        this->rate = rate;
    }

    double calcSalary() override 
    {
        return salary + (hrs * rate);
    }
    void accept(double value) override 
    {
        hrs = value;
        rate = value;
    }
};
int main() {
    const int NUM_EMPLOYEES = 2;
    Employee* employees[NUM_EMPLOYEES] = 
    {
        new PermEmployee(1, "RK", 50000, 5000, 10000),
        new ContractEmployee(2, "PK", 40, 160, 50)
    };

    for (int i = 0; i < NUM_EMPLOYEES; i++) 
    {
        employees[i]->display();
        cout << "Calculated Salary: " << employees[i]->calcSalary() << endl;

        // Update the employee's values
        employees[i]->accept(10000);
        cout << "Updated Calculated Salary: " << employees[i]->calcSalary() << endl;
        cout << endl;

        delete employees[i];
    }

    return 0;
}