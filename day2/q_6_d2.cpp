// Find binary equivalent of a decimal number using recursion
#include<iostream>
using namespace std;

int decimalToBinary(int decimal)
{
    if (decimal == 0) {
        return 0;
    }
    return decimal % 2 + 10 * decimalToBinary(decimal / 2);
}

int main()
{
    int decimal;
    cout << "Enter a decimal number: ";
    if (!(cin >> decimal)){
        cout << "Error: Invalid input. Please enter a valid number." << endl;
        return 1;
    }
    if (decimal == 0){
        cout << "The binary equivalent of " << decimal << " is: 0" << endl;
    } else{
        int binary = decimalToBinary(decimal);
        cout << "The binary equivalent of " << decimal << " is: " << binary << endl;
    }
    return 0;
}