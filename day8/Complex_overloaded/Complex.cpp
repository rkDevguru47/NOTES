#include "Complex.h"
#include <iostream>
using namespace std;

// Constructor
Complex::Complex(double r, double i): real(r), imag(i) {}

// Overloaded + operator
Complex Complex::operator+(const Complex& c)
{
    return Complex(real + c.real, imag + c.imag);
}

// Overloaded - operator
Complex Complex::operator-(const Complex& c) 
{
    return Complex(real - c.real, imag - c.imag);
}

// Overloaded * operator
Complex Complex::operator*(const Complex& c) 
{
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

// Overloaded / operator
Complex Complex::operator/(const Complex& c) 
{
    double denominator = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / denominator,
                   (imag * c.real - real * c.imag) / denominator);
}

// Display function
void Complex::display() 
{
    cout << real << " + " << imag << "i" << endl;
}

// Accept function
void Complex::accept() 
{
    cout << "Enter real part: ";
    cin >> real;
    cout << "Enter imaginary part: ";
    cin >> imag;
}