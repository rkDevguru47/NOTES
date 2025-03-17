#include <iostream>
#include "Account.h"

using namespace std;

const int MAX_ACCOUNTS = 100;

int main() {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;
    string accNum;
    double amount;

    do {
        cout << "\nAccount Management Menu:" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. Display account details" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                if (numAccounts < MAX_ACCOUNTS) {
                    accounts[numAccounts].accept();
                    cout << "Account created successfully." << endl;
                    cout << "Account Number: " << accounts[numAccounts].getAccountNumber() << endl;
                    numAccounts++;
                } else {
                    cout << "Maximum number of accounts reached." << endl;
                }
                break;
                }
            case 2:{
                cout << "Enter account number: ";
                cin >> accNum;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        accounts[i].display();
                        break;
                    }
                }
                break;
                }
            case 3:{
                cout << "Enter account number: ";
                cin >> accNum;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        accounts[i].withdraw(amount);
                        break;
                    }
                }
                break;
                }
            case 4:{
                cout << "Enter account number: ";
                cin >> accNum;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        accounts[i].deposit(amount);
                        break;
                    }
                }
                break;
                }
            case 5:{
                cout << "Exiting..." << endl;
                break;
                }
            default:{
                cout << "Invalid choice. Please try again." << endl;
                break;
                }
        }
    } while (choice != 5);

    return 0;
}
