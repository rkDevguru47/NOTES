#include <iostream>

using namespace std;

void multiplyByTwo(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int n;
    int* arr;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Dynamically allocate memory for the array
    arr = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to multiply each number by 2
    multiplyByTwo(arr, n);

    // Display the result
    cout << "The numbers multiplied by 2 are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocate the dynamically allocated memory
    delete[] arr;

    return 0;
}
