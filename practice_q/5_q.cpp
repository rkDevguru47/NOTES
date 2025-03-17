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

    virtual double calculate_salary() = 0;

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Joining: ";
        dateOfJoining.display();
        cout << "Salary: Rs. " << salary << endl;
    }
};

class Manager : virtual public Employee {
protected:
    double ta;
    double hra;

public:
    Manager(int id, string name, int d, int m, int y, double salary, double ta, double hra)
        : Employee(id, name, d, m, y, salary), ta(ta), hra(hra) {}

    double calculate_salary() override {
        return salary + ta + hra;
    }

    void display() {
        Employee::display();
        cout << "Travel Allowance: Rs. " << ta << endl;
        cout << "House Rent Allowance: Rs. " << hra << endl;
        cout << "Total Salary: Rs. " << calculate_salary() << endl;
    }
};

class SalesPerson : virtual public Employee {
protected:
    double sales;
    double commission;

public:
    SalesPerson(int id, string name, int d, int m, int y, double salary, double sales, double commission)
        : Employee(id, name, d, m, y, salary), sales(sales), commission(commission) {}

    double calculate_salary() override {
        return salary + (sales * commission);
    }

    void display() {
        Employee::display();
        cout << "Sales: Rs. " << sales << endl;
        cout << "Commission: " << (commission * 100) << "%" << endl;
        cout << "Total Salary: Rs. " << calculate_salary() << endl;
    }
};

class SalesManager : public Manager, public SalesPerson {
public:
    SalesManager(int id, string name, int d, int m, int y, double salary, double ta, double hra, double sales, double commission)
        : Employee(id, name, d, m, y, salary), Manager(id, name, d, m, y, salary, ta, hra), SalesPerson(id, name, d, m, y, salary, sales, commission) {}

    double calculate_salary() override {
        return Manager::calculate_salary() + SalesPerson::calculate_salary();
    }

    void display() {
        Employee::display();
        cout << "Travel Allowance: Rs. " << ta << endl;
        cout << "House Rent Allowance: Rs. " << hra << endl;
        cout << "Sales: Rs. " << sales << endl;
        cout << "Commission: " << (commission * 100) << "%" << endl;
        cout << "Total Salary: Rs. " << calculate_salary() << endl;
    }
};

int main() {
    SalesManager sm(101, "John Doe", 1, 1, 2022, 50000, 5000, 10000, 100000, 0.05);
    sm.display();

    return 0;
}
