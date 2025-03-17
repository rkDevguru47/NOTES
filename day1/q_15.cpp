#include<iostream>
using namespace std;

// Function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0 || n == 1){
        return 1;
    } else{
        return n * factorial(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter the number of terms in the factorial series: ";
    if (!(cin >> n)){
        cout << "Error: Invalid input. Please enter a single character." << endl;
        return 1;
    }
    cout << "Factorial series: ";
    for (int i = 0; i < n; i++)
    {
        cout << factorial(i) << " ";
    }
    cout << endl;
    return 0;
}
