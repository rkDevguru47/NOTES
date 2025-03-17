//Accept n numbers from users and store them into array then sort and display the sorted array.
#include<iostream>
using namespace std;

void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // int temp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = temp;
                swap(arr[j], arr[j + 1]);
            }
        }
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
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        if(!(cin >> arr[i])){
            cout << "Invalid input, please enter a valid number, exiting" << endl;
            return 1;
        };
    }
    sortArray(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}