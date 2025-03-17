// Find recursive running sum of n numbers
#include<iostream>
using namespace std;

// Recursive function to calculate the running sum
int sum(int n) 
{
    if (n == 0){
        return 0;
    }
    return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    if (!(cin >> n) || n < 0){
        cout << "Error: Invalid input. Please enter a positive integer." << endl;
        return 1;
    }
    cout << "Running sums up to " << n << " are: ";
    for (int i = 1; i <= n; i++){
        if (i > 1) {
            cout << ", ";
        }
        cout << sum(i);
    }
    cout << endl;
    return 0;
}