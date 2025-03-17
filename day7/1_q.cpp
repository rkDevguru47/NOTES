#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Default constructor
    Account() : accountNumber(0), accountHolderName(""), balance(0.0) {
        cout << "Default Constructor called. this pointer: " << this << endl;
    }

    // Parameterized constructor
    Account(int accNum, string accName, double bal) 
        : accountNumber(accNum), accountHolderName(accName), balance(bal) {
        cout << "Parameterized Constructor called. this pointer: " << this << endl;
    }

    // Function to accept account details
    void Accept() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);
        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Accept function called. this pointer: " << this << endl;
    }

    // Function to display account details
    void Display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Display function called. this pointer: " << this << endl;
    }

    // Function to deposit amount
    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid amount. Deposit failed." << endl;
        }
    }

    // Function to withdraw amount
    void Withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid amount or insufficient balance. Withdrawal failed." << endl;
        }
    }

    // Function to get account number
    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    const int MAX_ACCOUNTS = 100;
    Account* accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Open Account\n";
        cout << "2. Display Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (accountCount < MAX_ACCOUNTS) {
                    accounts[accountCount] = new Account();
                    accounts[accountCount]->Accept();
                    accountCount++;
                } else {
                    cout << "Maximum account limit reached." << endl;
                }
                break;
            }
            case 2: {
                int accNum;
                cout << "Enter Account Number to display: ";
                cin >> accNum;
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i]->getAccountNumber() == accNum) {
                        accounts[i]->Display();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 3: {
                int accNum;
                double amount;
                cout << "Enter Account Number to deposit: ";
                cin >> accNum;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i]->getAccountNumber() == accNum) {
                        accounts[i]->Deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 4: {
                int accNum;
                double amount;
                cout << "Enter Account Number to withdraw: ";
                cin >> accNum;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i]->getAccountNumber() == accNum) {
                        accounts[i]->Withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 5: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 5);

    // Clean up dynamically allocated memory
    for (int i = 0; i < accountCount; i++) {
        delete accounts[i];
    }

    return 0;
}