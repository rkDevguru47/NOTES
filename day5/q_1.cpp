// Declare function and call it by reference for swapping numbers

#include<iostream>
using namespace std;

int swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    if (!(cin >> a >> b)){
        cout << "Invalid input, please enter a valid number" << endl;
        return 1;
    }
    cout << "Before swapping: a = " << a << " b = " << b << endl;
    swap(a, b);
    cout << "After swapping: a = " << a << " b = " << b << endl;
    return 0;
}