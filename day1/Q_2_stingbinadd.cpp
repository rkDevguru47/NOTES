#include<iostream>
#include<string>
#include<bitset>
using namespace std;

// Function to add two numbers
int addNumbers(int a, int b)
{
    return a + b;
}
void convertToBinary(unsigned int n)
{
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
    printf("%d", n % 2);
}
string toBinary(int n)
{
    string r;
    while(n!=0) {
        r=(n%2==0 ?"0":"1")+r; 
        n/=2;
    }
    return r;
}
// Function to add two binary numbers using strings
string addBinary(string bin1, string bin2)
{
    int num1 = stoi(bin1, nullptr, 2);
    int num2 = stoi(bin2, nullptr, 2);
    int sum = num1 + num2;
    return bitset<32>(sum).to_string();
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
    string binary1 = "1010", binary2 = "1100";
    cout << "Adding two binary numbers: " << addBinary(binary1, binary2) << endl;
    
    // Adding two characters
    char char1 = 'A', char2 = 'B';
    cout << "Adding two characters: " << addCharacters(char1, char2) << endl;
    
    return 0;
}