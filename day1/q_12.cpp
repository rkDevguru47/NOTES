#include <iostream>
using namespace std;

// Function to check if a given character is a uppercase or lowercase letter
int main()
{
    char ch;
    // Get user input
    cout << "Enter a character: ";
    if (!(cin >> ch)){
        cout << "Error: Invalid input. Please enter a single character." << endl;
        return 1;
    }
    // Check if the character is a small or capital letter
    if (ch >= 'a' && ch <= 'z'){
        cout << "The character '" << ch << "' is a small letter." << endl;
    } else if (ch >= 'A' && ch <= 'Z'){
        cout << "The character '" << ch << "' is a capital letter." << endl;
    } else{
        cout << "The character '" << ch << "' is not a letter." << endl;
    }
    return 0;
}
