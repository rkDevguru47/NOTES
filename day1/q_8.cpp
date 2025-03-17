#include<iostream>
using namespace std;

// Recursive function to generate the Fibonacci series
int fibonacci(int n)
{
    if (n <= 1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    // Get the number of Fibonacci terms from the user
    cout << "Enter the number of Fibonacci terms to generate: ";
    if (!(cin >> n)){
        cout << "Error: Invalid input. Please enter valid value of n." << endl;
        return 1;
    }
    cout << "The first " << n << " Fibonacci numbers are: ";
    // Generate and print the Fibonacci series
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}
