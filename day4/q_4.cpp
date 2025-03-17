// To multiply each element of an array by 2
#include<iostream>
using namespace std;

void multiplyByTwo(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] =arr[i] * 2;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    if (!(cin >> n)){
        cout << "Invalid input, please enter a valid number" << endl;
        return 1;
    }
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        if (!(cin >> arr[i])){
            cout << "Invalid input, please enter a valid number, exiting" << endl;
            return 1;
        }
    }
    multiplyByTwo(arr, n);
    cout << "Modified array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}