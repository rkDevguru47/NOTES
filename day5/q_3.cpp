// Function for printing factorial series with recursive

#include<iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0) {
        return 1;
    }
    int result = n * factorial(n - 1);
    cout << "Factorial of " << n << " is " << result << endl;
    return result;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    if (!(cin >> n)){
        cout << "Invalid input, please enter a valid number" << endl;
        return 1;
    }
    factorial(n);
    return 0;
}