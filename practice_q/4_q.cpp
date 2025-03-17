#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Employee {
protected:
    int id;
    string name;
    Date dateOfJoining;
    double salary;

public:
    Employee(int id, string name, int d, int m, int y, double salary)
        : id(id), name(name), dateOfJoining(d, m, y), salary(salary) {}

    virtual double calculate() = 0;

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Joining: ";
        dateOfJoining.display();
        cout << "Salary: Rs. " << salary << endl;
    }
};

class Manager : public Employee {
private:
    double ta;
    double hra;

public:
    Manager(int id, string name, int d, int m, int y, double salary, double ta, double hra)
        : Employee(id, name, d, m, y, salary), ta(ta), hra(hra) {}

    double calculate() override {
        return salary + ta + hra;
    }

    void display() {
        Employee::display();
        cout << "Travel Allowance: Rs. " << ta << endl;
        cout << "House Rent Allowance: Rs. " << hra << endl;
        cout << "Total Salary: Rs. " << calculate() << endl;
    }
};

class SalesPerson : public Employee {
private:
    double sales;
    double commission;

public:
    SalesPerson(int id, string name, int d, int m, int y, double salary, double sales, double commission)
        : Employee(id, name, d, m, y, salary), sales(sales), commission(commission) {}

    double calculate() override {
        return salary + (sales * commission);
    }

    void display() {
        Employee::display();
        cout << "Sales: Rs. " << sales << endl;
        cout << "Commission: " << (commission * 100) << "%" << endl;
        cout << "Total Salary: Rs. " << calculate() << endl;
    }
};

class WageEmp : public SalesPerson {
private:
    double rate;

public:
    WageEmp(int id, string name, int d, int m, int y, double salary, double sales, double commission, double rate)
        : SalesPerson(id, name, d, m, y, salary, sales, commission), rate(rate) {}

    double calculate() override {
        return (salary + (sales * commission)) + rate;
    }

    void display() {
        SalesPerson::display();
        cout << "Wage Rate: Rs. " << rate << endl;
        cout << "Total Salary: Rs. " << calculate() << endl;
    }
};

int main() {
    Employee* emp1 = new Manager(101, "John Doe", 1, 1, 2022, 50000, 5000, 10000);
    Employee* emp2 = new SalesPerson(102, "Jane Smith", 15, 3, 2021, 40000, 100000, 0.05);
    Employee* emp3 = new WageEmp(103, "Bob Johnson", 30, 6, 2020, 30000, 50000, 0.1, 5000);

    emp1->display();
    cout << endl;
    emp2->display();
    cout << endl;
    emp3->display();

    delete emp1;
    delete emp2;
    delete emp3;

    return 0;
}
