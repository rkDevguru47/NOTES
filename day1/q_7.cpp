#include<iostream>
using namespace std;

// Function to calculate the sum of digits using a loop
int sumOfDigitsLoop(int num)
{
    int sum = 0;
    while (num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to calculate the sum of digits using recursion
int sumOfDigitsRecursive(int num)
{
    if (num == 0){
        return 0;
    }
    return num % 10 + sumOfDigitsRecursive(num / 10);
}

int main()
{
    int num;
    // Get the 4-digit number from the user
    cout << "Enter a 4-digit number: ";
    if (!(cin >> num) || num < 1000 || num > 9999){
        cout << "Error: Invalid input. Please enter a 4-digit number." << endl;
        return 1;
    }
    // Calculate the sum of digits using a loop
    int sumLoop = sumOfDigitsLoop(num);
    cout << "Sum of digits (using loop): " << sumLoop << endl;
    // Calculate the sum of digits using recursion
    int sumRecursive = sumOfDigitsRecursive(num);
    cout << "Sum of digits (using recursion): " << sumRecursive << endl;
    return 0;
}
