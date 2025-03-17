#include <iostream>

using namespace std;

class Math1 {
public:
    int Add(int a, int b) {
        return a + b;
    }

    int Sub(int a, int b) {
        return a - b;
    }

    virtual double CalArea() {
        return 0.0;
    }
};

class Math2 {
public:
    int Mul(int a, int b) {
        return a * b;
    }

    int Div(int a, int b) {
        return a / b;
    }

    virtual double CalArea() {
        return 0.0;
    }
};

class Calculator : public virtual Math1, public virtual Math2 {
public:
    double CalArea() override {
        return Math1::CalArea() + Math2::CalArea();
    }
};

int main() {
    Calculator calc;
    cout << "CalArea() result: " << calc.CalArea() << endl;
    return 0;
}
