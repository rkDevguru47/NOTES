// Find given number is odd or even
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    if (!(cin >> num)){
        cout << "Error: Invalid input. Please enter an integer." << endl;
    }
    // Check if the number is odd or even
    if (num % 2 == 0){
        cout << "The number " << num << " is even." << endl;
    } 
    else{
        cout << "The number " << num << " is odd." << endl;
    }
    return 0;
}