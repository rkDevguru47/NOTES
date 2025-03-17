#ifndef __COMPLEX_H__
#define __COMPLEX_H__

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0);
    Complex add(Complex c);
    Complex subtract(Complex c);
    Complex multiply(Complex c);
    Complex divide(Complex c);
    void display();
    void accept();
};

#endif 
