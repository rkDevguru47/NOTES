#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

// Function to accept n numbers and store them in a dynamically allocated array
void acceptNumbers(int*& arr, int& n) {
    cout << "Enter the number of elements: ";
    cin >> n;
    arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Function to sort and display the sorted array
void sortAndDisplay(int* arr, int n) {
    sort(arr, arr + n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to accept n characters and print them as a string
void acceptAndPrintString() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    char* arr = new char[n + 1];
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr[n] = '\0'; // Null-terminate the string
    cout << "The string is: " << arr << endl;
    delete[] arr;
}

// Function to find and display the average of n numbers
void findAndDisplayAverage(int* arr, int n) {
    double sum = accumulate(arr, arr + n, 0);
    double average = sum / n;
    cout << "The average is: " << average << endl;
}

// Function to multiply each number by 2 and display the result
void multiplyAndDisplay(int* arr, int n) {
    cout << "Array after multiplying each element by 2: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] * 2 << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    int* arr = nullptr;
    int n = 0;

    do {
        cout << "Menu:" << endl;
        cout << "1. Accept n numbers and sort them" << endl;
        cout << "2. Accept n characters and print as string" << endl;
        cout << "3. Find and display average of n numbers" << endl;
        cout << "4. Multiply each number by 2 and display result" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acceptNumbers(arr, n);
                sortAndDisplay(arr, n);
                delete[] arr;
                arr = nullptr;
                break;
            case 2:
                acceptAndPrintString();
                break;
            case 3:
                acceptNumbers(arr, n);
                findAndDisplayAverage(arr, n);
                delete[] arr;
                arr = nullptr;
                break;
            case 4:
                acceptNumbers(arr, n);
                multiplyAndDisplay(arr, n);
                delete[] arr;
                arr = nullptr;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 5);

    return 0;
}