// Recursive function to find n numbers in Fibonacci series
#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    cout << "Enter the number of Fibonacci terms to generate: ";
    if (!(cin >> n)){
        cout << "Error: Invalid input. Please enter valid value of n." << endl;
        return 1;
    }
    cout << "The first " << n << " Fibonacci numbers are: ";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}