#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    friend Complex operator++(Complex& c);
    friend Complex operator++(Complex& c, int);
    friend Complex operator+(const Complex& c, int n);
    friend Complex operator+(int n, const Complex& c);
    friend ostream& operator<<(ostream& os, const Complex& c);
};

Complex operator++(Complex& c) {
    c.real++;
    c.imag++;
    return c;
}

Complex operator++(Complex& c, int) {
    Complex temp(c);
    c.real++;
    c.imag++;
    return temp;
}

Complex operator+(const Complex& c, int n) {
    return Complex(c.real + n, c.imag);
}

Complex operator+(int n, const Complex& c) {
    return Complex(c.real + n, c.imag);
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    Complex c1(10, 20);
    Complex c2 = c1++;
    Complex c3 = ++c1;
    Complex c4 = c1 + 5;
    Complex c5 = 5 + c1;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;
    cout << "c4: " << c4 << endl;
    cout << "c5: " << c5 << endl;

    return 0;
}
