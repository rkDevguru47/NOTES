#ifndef __COMPLEX_H___
#define __COMPLEX_H___

class Complex {
private:
    double real;
    double imag;
    static int objectCount; // Static data member to track object count

public:
    // No-arg constructor
    Complex();

    // Parameterized constructor
    Complex(double r, double i);
    Complex add(Complex c);
    Complex subtract(Complex c);
    Complex multiply(Complex c);
    Complex divide(Complex c);
    void accept();
    void display();
    // Get the number of objects created
    static int getObjectCount();
};

#endif 
