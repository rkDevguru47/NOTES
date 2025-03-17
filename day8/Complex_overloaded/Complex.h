#ifndef __COMPLEX_H__
#define __COMPLEX_H__

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0);

    // Overloaded operators
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);

    void display();
    void accept();
};

#endif