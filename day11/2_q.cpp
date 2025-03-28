#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Array {
private:
    T* data;
    int size;

public:
    Array(int s) {
        size = s;
        data = new T[size];
    }

    void set(int index, T value) {
        data[index] = value;
    }

    T get(int index) {
        return data[index];
    }

    int getSize() {
        return size;
    }

    void sort() {
        std::sort(data, data + size);
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    int choice, size;
    char dataType;

    cout << "Enter the data type (i for int, f for float, c for char): ";
    cin >> dataType;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (dataType == 'i') {
        Array<int> intArray(size);
        while (true) {
            cout << "\nMenu:\n1. Store data\n2. Display data\n3. Sort data\n4. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    for (int i = 0; i < size; i++) {
                        int value;
                        cout << "Enter value for index " << i << ": ";
                        cin >> value;
                        intArray.set(i, value);
                    }
                    break;
                case 2:
                    cout << "Array elements: ";
                    for (int i = 0; i < size; i++) {
                        cout << intArray.get(i) << " ";
                    }
                    cout << endl;
                    break;
                case 3:
                    intArray.sort();
                    cout << "Array sorted in ascending order." << endl;
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } else if (dataType == 'f') {
        Array<float> floatArray(size);
        while (true) {
            cout << "\nMenu:\n1. Store data\n2. Display data\n3. Sort data\n4. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    for (int i = 0; i < size; i++) {
                        float value;
                        cout << "Enter value for index " << i << ": ";
                        cin >> value;
                        floatArray.set(i, value);
                    }
                    break;
                case 2:
                    cout << "Array elements: ";
                    for (int i = 0; i < size; i++) {
                        cout << floatArray.get(i) << " ";
                    }
                    cout << endl;
                    break;
                case 3:
                    floatArray.sort();
                    cout << "Array sorted in ascending order." << endl;
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } else if (dataType == 'c') {
        Array<char> charArray(size);
        while (true) {
            cout << "\nMenu:\n1. Store data\n2. Display data\n3. Sort data\n4. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    for (int i = 0; i < size; i++) {
                        char value;
                        cout << "Enter value for index " << i << ": ";
                        cin >> value;
                        charArray.set(i, value);
                    }
                    break;
                
                case 2:
                    cout << "Array elements: ";
                    for (int i = 0; i < size; i++) {
                        cout << charArray.get(i) << " ";
                    }
                    cout << endl;
                    break;
                case 3:
                    charArray.sort();
                    cout << "Array sorted in ascending order." << endl;
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } else {
        cout << "Invalid data type. Please try again." << endl;
    }
    return 0;
}