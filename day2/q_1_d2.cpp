//to find the roots of a quadratic equations
#include<iostream>
using namespace std;
#include<cmath>
int main()
{
    double a, b, c;
    cout << "Enter the coefficients a, b, and c of the quadratic equation (ax^2 + bx + c = 0): ";
    if (!(cin >> a >> b >> c))
    {
        cout << "Invalid input. Please enter valid coefficients." << endl;
        return 1;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0)
    {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "The roots are real and distinct." << endl;
        cout << "Root 1: " << root1 << endl;
        cout << "Root 2: " << root2 << endl;
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        cout << "The roots are real and same." << endl;
        cout << "Root: " << root << endl;
    }
    else
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "The roots are complex and distinct." << endl;
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}