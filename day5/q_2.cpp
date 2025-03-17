// To print the elements of an array using a function 
#include<iostream>
using namespace std;

struct Student
{
    int* arr;
    int n;
};

int printArray(Student& s)
{
    for (int i = 0; i < s.n; i++) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    Student s;
    cout << "Enter the size of the array: ";
    if (!(cin >> s.n)) {
        cout << "Invalid input, please enter a valid number" << endl;
        return 1;
    }
    s.arr = new int[s.n];
    for (int i = 0; i < s.n; i++) {
        cout << "Enter the element at index " << i << ": ";
        if (!(cin >> s.arr[i])) {
            cout << "Invalid input, please enter a valid number" << endl;
            delete[] s.arr;
            return 1;
        }
    }
    cout << "The array is: ";
    printArray(s);
    delete[] s.arr;
    return 0;
}
