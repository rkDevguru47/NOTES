#include <iostream>
#include <string>
#include <exception>

using namespace std;

class LowBalanceException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Minimum balance of Rs. 1000 is required.";
    }
};

class PanCardRequiredException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: PAN card is required for deposits of Rs. 50,000 or more.";
    }
};

class Account {
private:
    int acno;
    string name;
    double balance;

public:
    Account(int acno, string name, double balance) {
        this->acno = acno;
        this->name = name;
        this->balance = balance;
    }

    void accept() {
        cout << "Enter account number: ";
        cin >> acno;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void display() {
        cout << "Account Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance - amount < 1000) {
            throw LowBalanceException();
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: Rs. " << balance << endl;
    }

    void deposit(double amount) {
        if (amount >= 50000) {
            throw PanCardRequiredException();
        }
        balance += amount;
        cout << "Deposit successful. New balance: Rs. " << balance << endl;
    }
};

int main() {
    Account acc(101, "John Doe", 5000);

    try {
        acc.withdraw(5000);
    } catch (const LowBalanceException& e) {
        cout << e.what() << endl;
    }

    try {
        acc.deposit(60000);
    } catch (const PanCardRequiredException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
