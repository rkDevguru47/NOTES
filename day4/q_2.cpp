//Accept n characters from the user and print it as a string.
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of characters: " << endl;
    if(!(cin>>n)){
        cout << "Invalid input, please enter a valid number" << endl;
        return 1;
    }
    char a[n];
    for(int i=0; i<n; i++)
    {
        cout << "Enter the characters for number "<< i+1 <<": ";
        if(!(cin>>a[i])){
            cout << "Invalid input, please enter a valid character, exiting" << endl;
            return 1;
        }
    }
    cout << "The string is: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
    }
    return 0;
}