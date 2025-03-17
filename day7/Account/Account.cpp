#include "Account.h"
using namespace std;

Account::Account() : accountNumber("0000"), accountHolder("Unknown"), balance(0.0) 
{
    cout << "Default constructor called. This pointer: " << this <<  endl;
}

Account::Account( string accNum,  string accHolder, double bal) : 
accountNumber(accNum), accountHolder(accHolder), balance(bal) 
{
    cout << "Parameterized constructor called. This pointer: " << this <<  endl;
}

void Account::accept() 
{
     cout << "Enter account number: ";
     cin >> accountNumber;
     cout << "Enter account holder name: ";
     cin >> accountHolder;
     cout << "Enter initial balance: ";
     cin >> balance;
     cout << "Account created. This pointer: " << this <<  endl;
}

void Account::display() 
{
    cout << "Account Number: " << accountNumber <<  endl;
    cout << "Account Holder: " << accountHolder <<  endl;
    cout << "Balance (in Rupees): " << balance <<  endl;
    cout << "This pointer: " << this <<  endl;
}

void Account::withdraw(double amount) 
{
    if (balance >= amount) {
        balance = balance - amount;
        cout << "Withdrawal successful. New balance: Rs " << balance <<  endl;
    } else {
        cout << "Insufficient funds." <<  endl;
    }
}

void Account::deposit(double amount) 
{
    balance = balance + amount;
    cout << "Deposit successful. New balance: Rs " << balance <<  endl;
}

string Account::getAccountNumber() 
{
    return accountNumber;
}