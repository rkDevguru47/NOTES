#ifndef ___ACCOUNT_H__
#define ___ACCOUNT_H__


#include<iostream>
#include<string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(); // Default constructor
    Account(string, string, double); // Parameterized constructor
    void accept();
    void display();
    void withdraw(double);
    void deposit(double);
    string getAccountNumber();
};

#endif 
