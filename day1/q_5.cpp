#include<iostream>
using namespace std;

// Function to swap two numbers
void swapNumbers(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int num1 = 10, num2 = 20;
    cout << "Before swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    // Call function to swap the values
    swapNumbers(num1, num2);
    cout << "After swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    return 0;
}
