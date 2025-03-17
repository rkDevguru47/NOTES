#include "Account.h"
#include<iostream>
#include<string>

using namespace std;

int Account::nextAccountNumber = 1001; // Initialize the static data member

Account::Account() 
{
    accountHolder = "Unknown";
    balance = 0.0;
    accountNumber = generateAccountNumber();
    cout << "Default constructor called. This pointer: " << this << endl;
}

Account::Account(string accHolder, string accNum, double bal)
{
    accountHolder = accHolder;
    balance = bal;
    accountNumber = generateAccountNumber();
    cout << "Parameterized constructor called. This pointer: " << this << endl;
}

void Account::accept() {
    
    cout << "Enter account holder name: ";
    cin >> accountHolder;
    cout << "Enter initial balance: ";
    cin >> balance;
    accountNumber = generateAccountNumber();
    cout << "Account created. This pointer: " << this << endl;
}

void Account::display() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << accountHolder << endl;
    cout << "Balance (in Rupees): " << balance << endl;
    cout << "This pointer: " << this << endl;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Withdrawal successful. New balance: Rs " << balance << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
}

void Account::deposit(double amount) {
    balance += amount;
    cout << "Deposit successful. New balance: Rs " << balance << endl;
}

string Account::getAccountNumber() {
    return accountNumber;
}

string Account::generateAccountNumber() {
    string accNum = "ACC" + to_string(nextAccountNumber);
    nextAccountNumber++;
    return accNum;
}
