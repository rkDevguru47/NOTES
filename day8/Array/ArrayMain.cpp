#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    Array arr(n);
    arr.accept();
    arr.display();

    cout << "Sorting the array..." << endl;
    arr.sorted();
    arr.display();

    cout << "Maximum element: " << arr.findMax() << endl;
    cout << "Minimum element: " << arr.findMin() << endl;

    return 0;
}
