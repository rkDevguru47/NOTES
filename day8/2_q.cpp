#include <iostream>
using namespace std;

int factorial(const int& n) {
    // Attempt to modify the value of n
    // n = 0; 
    // This will not compile because n is a const reference
    
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int x;
    cout << "Enter a number: " << endl;
    if (!(cin >> x)) {
        cout << "Invalid input, please enter a valid number" << endl;
        return 1;
    }
    cout << "Factorial of " << x << " is: " << factorial(x) << endl;
    return 0;
}
