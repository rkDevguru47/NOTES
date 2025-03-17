// Find if entered character is a small letter or capital letter
#include<iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character: ";
    if (!(cin >> ch)){
        cout << "Error: Invalid input. Please enter a character." << endl;
        return 1;
    }
    if (ch >= 'a' && ch <= 'z'){
        cout << "The character '" << ch << "' is a small letter." << endl;
    }
    else if (ch >= 'A' && ch <= 'Z'){
        cout << "The character '" << ch << "' is a capital letter." << endl;
    }
    else{
        cout << "The character '" << ch << "' is not an alphabet." << endl;
    }
    return 0;
}