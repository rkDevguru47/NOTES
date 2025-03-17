#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

// Initialize the static data member
int Complex::objectCount = 0;

// No-arg constructor
Complex::Complex(): real(0), imag(0) {
    objectCount++;
}

// Parameterized constructor
Complex::Complex(double r, double i): real(r), imag(i) {
    objectCount++;
}

Complex Complex::add(Complex c) {
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::subtract(Complex c) {
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::multiply(Complex c) {
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::divide(Complex c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
}

void Complex::display() {
    if (imag >= 0) {
        cout << real << " + " << imag << "i" << std::endl;
    } else {
        cout << real << " - " << abs(imag) << "i" << std::endl;
    }
}
void Complex::accept() {
    cout << "Enter real and imaginary parts: ";
    cin >> real >> imag;
}

// Get the number of objects created
int Complex::getObjectCount() {
    return objectCount;
}
