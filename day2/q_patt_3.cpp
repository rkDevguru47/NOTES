// To print n rows of the hollow diamond pattern and its filled version:
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// **      **
// ***    ***
// ****  ****
// **********

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    if(!(cin >> n)){
        cout << "Invalid input. Please enter a valid number of rows." << endl;
        return 1;
    }
    
    // Upper half of the hollow diamond pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2*i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n-i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower half of the hollow diamond pattern
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2*(n-i-1); j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "Filled diamond pattern:" << endl;
    // Upper half of the filled diamond pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower half of the filled diamond pattern
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}