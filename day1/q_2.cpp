#include<iostream>
using namespace std;

// Function to add two numbers
int addNumbers(int a, int b)
{
    return a + b;
}

// Function to add two binary numbers
int addBinary(int bin1, int bin2)
{
    // Convert binary numbers to decimal
    int dec1 = 0, dec2 = 0;
    int power = 1;
    while (bin1 > 0)
    {
        dec1 = dec1 + (bin1 % 10) * power;
        power = power * 2;
        bin1 = bin1 / 10;
    }
    power = 1;
    while (bin2 > 0)
    {
        dec2 = dec2 + (bin2 % 10) * power;
        power = power * 2;
        bin2 = bin2 / 10;
    }
    // Add the decimal numbers and convert the result back to binary
    int bin_sum = dec1 + dec2;
    int binary_sum = 0, place = 1;
    while (bin_sum > 0)
    {
        binary_sum = binary_sum + (bin_sum % 2) * place;
        place = place * 10;
        bin_sum = bin_sum / 2;
    }
    return binary_sum;
}

// Function to add two characters
int addCharacters(char a, char b)
{
    int ascii_sum = a + b;
    return ascii_sum;
}

int main()
{
    // Adding two numbers
    int num1 = 10, num2 = 20;
    cout << "Adding two numbers: " << addNumbers(num1, num2) << endl;
    // Adding two binary numbers
    int binary1 = 1010, binary2 = 1100;
    cout << "Adding two binary numbers: " << addBinary(binary1, binary2) << endl;
    // Adding two characters
    char char1 = 'A', char2 = 'B';
    cout << "Adding two characters: " << addCharacters(char1, char2) << endl;
    return 0;
}
