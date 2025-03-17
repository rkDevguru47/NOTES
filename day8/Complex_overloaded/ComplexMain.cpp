#include "Complex.h"
#include <iostream>
using namespace std;

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);

    cout << "c1 = ";
    c1.display();

    cout << "c2 = ";
    c2.display();

    Complex c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.display();

    c3 = c1 - c2;
    cout << "c1 - c2 = ";
    c3.display();

    c3 = c1 * c2;
    cout << "c1 * c2 = ";
    c3.display();

    c3 = c1 / c2;
    cout << "c1 / c2 = ";
    c3.display();

    return 0;
}