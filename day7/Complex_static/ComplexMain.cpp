#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    int choice;
    Complex c1, c2, result;

    cout << "Number of Complex objects created: " << Complex::getObjectCount() << endl;

    do {
        cout << "Complex Number Operations:" << endl;
        cout << "1. Add two complex numbers" << endl;
        cout << "2. Subtract two complex numbers" << endl;
        cout << "3. Multiply two complex numbers" << endl;
        cout << "4. Divide two complex numbers" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the first complex number:" << endl;
                c1.accept();
                cout << "Enter the second complex number:" << endl;
                c2.accept();
                result = c1.add(c2);
                cout << "The sum of the two complex numbers is: ";
                result.display();
                break;
            case 2:
                cout << "Enter the first complex number:" << endl;
                c1.accept();
                cout << "Enter the second complex number:" << endl;
                c2.accept();
                result = c1.subtract(c2);
                cout << "The difference of the two complex numbers is: ";
                result.display();
                break;
            case 3:
                cout << "Enter the first complex number:" << endl;
                c1.accept();
                cout << "Enter the second complex number:" << endl;
                c2.accept();
                result = c1.multiply(c2);
                cout << "The product of the two complex numbers is: ";
                result.display();
                break;
            case 4:
                cout << "Enter the first complex number:" << endl;
                c1.accept();
                cout << "Enter the second complex number:" << endl;
                c2.accept();
                result = c1.divide(c2);
                cout << "The quotient of the two complex numbers is: ";
                result.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    cout << "Number of Complex objects created: " << Complex::getObjectCount() << endl;

    return 0;
}
