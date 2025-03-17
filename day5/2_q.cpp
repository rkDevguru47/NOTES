#include <iostream>
#include <algorithm>

using namespace std;

void sortAndDisplayArray(int* arr, int n) {
    // Sort the array using the standard library's sort function
    sort(arr, arr + n);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, n;
    int* arr;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Accept and store numbers" << endl;
        cout << "2. Sort and display array" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Accept and store numbers
                cout << "Enter the number of elements: ";
                cin >> n;
                arr = new int[n];
                cout << "Enter the elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Numbers stored successfully." << endl;
                break;

            case 2:
                // Sort and display array
                if (arr == nullptr) {
                    cout << "No numbers have been stored yet." << endl;
                } else {
                    sortAndDisplayArray(arr, n);
                }
                break;

            case 3:
                // Exit the program
                cout << "Exiting the program..." << endl;
                delete[] arr;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
