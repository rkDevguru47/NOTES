#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Addition
Complex Complex::add(Complex c) {
    return Complex(real + c.real, imag + c.imag);
}

// Subtraction
Complex Complex::subtract(Complex c) {
    return Complex(real - c.real, imag - c.imag);
}

// Multiplication
Complex Complex::multiply(Complex c) {
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

// Division
Complex Complex::divide(Complex c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
}

// Display
void Complex::display() {
    if (imag >= 0) {
        std::cout << real << " + " << imag << "i" << std::endl;
    } else {
        std::cout << real << " - " << abs(imag) << "i" << std::endl;
    }
}

void Complex::accept() {
    cout << "Enter real and imaginary parts: ";
    cin >> real >> imag;
}