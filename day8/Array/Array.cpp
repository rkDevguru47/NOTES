#include "Array.h"
#include <iostream>
#include <algorithm>
using namespace std;

Array::Array(int n) {
    size = n;
    arr = new int[size];
    cout << "Array created with size: " << size << endl;
}

Array::~Array() {
    delete[] arr;
    cout << "Array destroyed." << endl;
}

void Array::accept() {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void Array::display() {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::sorted() {
    sort(arr, arr + size);
}

int Array::findMax() {
    return *max_element(arr, arr + size);
}

int Array::findMin() {
    return *min_element(arr, arr + size);
}
