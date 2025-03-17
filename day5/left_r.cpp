#include <iostream>
using namespace std;
void leftRotate(int arr[], int size, int n) {
    n = n % size; // Handle the case where n is greater than the array size

    // Reverse the entire array
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }

    // Reverse the first n elements
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - 1 - i]);
    }

    // Reverse the remaining elements
    for (int i = n; i < (n + size) / 2; i++) {
        swap(arr[i], arr[size - 1 - (i - n)]);
    }
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int n;
    cout << "Enter the number of positions to left rotate: ";
    cin >> n;

    leftRotate(arr, size, n);

    cout << "The left rotated array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
