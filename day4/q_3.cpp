// To find the average of n numbers entered by the user
#include<iostream>
using namespace std;

int main()
{
    int i, n, sum=0;
    float avg;
    cout<<"Enter the number of elements: ";
    if(!(cin>>n)){
        cout << "Invalid input, please enter a valid number" << endl;
        return 1;
    }
    int arr[n];
    cout<<"Enter the elements: ";
    for(i=0; i<n; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        if(!(cin>>arr[i])){
            cout << "Invalid input, please enter a valid number, exiting" << endl;
            return 1;
        }
        sum+=arr[i];
    }
    avg=(float)sum/n;
    cout<<"The average is: "<<avg;
    return 0;
}