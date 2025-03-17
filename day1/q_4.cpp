//Calculate power of a number
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double b, exp;
    cout << "Enter the base: ";
    if (!(cin >> b)){
        cout << "Error: Invalid input. Please enter a single nuber." << endl;
        return 1;
    }
    cout << "Enter the exponent:";
    if (!(cin >> exp)){
        cout << "Error: Invalid input. Please enter a single number." << endl;
        return 1;
    }
    double result = pow(b, exp);
    cout << "The result is: " << result;
    return 0;
}