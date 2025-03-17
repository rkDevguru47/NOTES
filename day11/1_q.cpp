#include <iostream>
using namespace std;

template <class T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T add(T a, T b) {
    return a + b;
}

template <class T>
T subtract(T a, T b) {
    return a - b;
}

template <class T>
T multiply(T a, T b) {
    return a * b;
}

template <class T>
T divide(T a, T b) {
    return a / b;
}

int main() {
    int a, b;
    double c, d;

    cout << "Enter two numbers: ";
    if (!(cin >> a >> b)){
        cout << "Invalid input" << endl;
        return 1;
    }
    cout << "Swap function:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    Swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    cout << "\nAdd function: " << add(a, b) << endl;
    cout << "Subtract function: " << subtract(a, b) << endl;
    cout << "Multiply function: " << multiply(a, b) << endl;
    cout << "Divide function: " << divide(a, b) << endl;

    cout << "Enter two floating numbers: ";
    if (!(cin >> c >> d)){
        cout << "Invalid input" << endl;
        return 1;
    }

    cout << "Swap function:" << endl;
    cout << "c = " << c << ", d = " << d << endl;
    Swap(c, d);
    cout << "After swap: c = " << c << ", d = " << d << endl;
    cout << "\nAdd function: " << add(c, d) << endl;
    cout << "Subtract function: " << subtract(c, d) << endl;
    cout << "Multiply function: " << multiply(c, d) << endl;
    cout << "Divide function: " << divide(c, d) << endl;

    return 0;
}
