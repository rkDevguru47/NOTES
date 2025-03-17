#include<iostream>
using namespace std;

// Recursive function to convert decimal to binary
void decimalToBinary(int decimal)
{
    if (decimal == 0){
        return;
    }
    decimalToBinary(decimal / 2);
    cout << (decimal % 2);
}

int main()
{
    int decimal;
    // Get the decimal number from the user
    cout << "Enter a decimal number: ";
    if (!(cin >> decimal)){
        cout << "Error: Invalid input. Please enter a valid number." << endl;
        return 1;
    }
    // Handle the case when the input is 0
    if (decimal == 0){
        cout << "The binary equivalent of 0 is: 0" << endl;
    } else{
        cout << "The binary equivalent of " << decimal << " is: ";
        // Convert the decimal number to binary using the recursive function
        decimalToBinary(decimal);
        cout << endl;
    }
    return 0;
}
