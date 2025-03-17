// To print n rows of the following pattern and its flipped version:
// *****
//  ****
//   ***
//    **
//     *

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    if (!(cin >> n))
    {
        cout<<"Invalid input. Please enter a valid number of rows."<<endl;
        return 1;
    }
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= i-1; j++)
        {
            cout<<" ";
        }
        for(int j = 1; j <= n-i+1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    cout << "Flipped pattern:" << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for(int j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
