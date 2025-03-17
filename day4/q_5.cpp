// To find the minimum, maximum, second maximum and second minimum element of an array
#include<iostream>
#include<climits>
using namespace std;

int findMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int findSecondMax(int arr[], int n)
{
    int max = findMax(arr, n);
    int secondMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != max && arr[i] > secondMax)
        {
            secondMax = arr[i];
        }
    }
    if(secondMax == INT_MIN){
        return -1;
    }
    else{
        return secondMax;
    }
}

int findSecondMin(int arr[], int n)
{
    int min = findMin(arr, n);
    int secondMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != min && arr[i] < secondMin)
        {
            secondMin = arr[i];
        }
    }
    if(secondMin == INT_MAX){
        return -1;
    }
    else{
        return secondMin;
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
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        if (!(cin >> arr[i])){
            cout << "Invalid input, please enter a valid number, exiting" << endl;
            return 1;
        }
    }
    int min = findMin(arr, n);
    int max = findMax(arr, n);
    int secondMax = findSecondMax(arr, n);
    int secondMin = findSecondMin(arr, n);
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;
    cout << "Second maximum element: " << secondMax << endl;
    cout << "Second minimum element: " << secondMin << endl;
    return 0;
}