// To Reverse string (char array) with recursion

#include<iostream>
using namespace std;

int reverse(char arr[], int start, int end)
{
    if (start >= end){
        return 0;
    }
    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
    return 0;
}

int main()
{
    cout<<"Enter the size of the array: ";
    int n;
    if(!(cin >> n)){
        cout<<"Invalid input, please enter a valid character" << endl;
        return 1;
    }
    char arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the element at index " << i << ": ";
        if(!(cin >> arr[i])){
            cout << "Invalid input, please enter a valid character, exiting" << endl;
            return 1;
        }
    }
    reverse(arr, 0, n-1);
    cout<<"The reversed array is: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}