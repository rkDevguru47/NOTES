#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    char* charArray;
    string str;

    cout << "Enter the number of characters: ";
    cin >> n;

    // Dynamically allocate memory for the character array
    charArray = new char[n + 1];  // Add 1 for the null terminator

    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> charArray[i];
    }

    // Null-terminate the character array
    charArray[n] = '\0';

    // Convert the character array to a string
    str = charArray;

    cout << "The string is: " << str << endl;

    // Deallocate the dynamically allocated memory
    delete[] charArray;

    return 0;
}
