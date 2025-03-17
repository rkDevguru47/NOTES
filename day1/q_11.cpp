#include<iostream>
using namespace std;

int main()
{
    int num;
    // Get user input
    cout << "Enter a number: ";
    if (!(cin >> num)){
        cout << "Error: Invalid input. Please enter an integer." << endl;
        return 1;
    }
    // Check if the number is odd or even
    if (num % 2 == 0){
        cout << "The number " << num << " is even." << endl;
    } else{
        cout << "The number " << num << " is odd." << endl;
    }
    return 0;
}
