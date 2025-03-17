#include <iostream>
using namespace std;

// Recursive function to calculate the running sum
int runningSum(int n)
{
    if (n == 0){
        return n;
    } 
    return n + runningSum(n - 1);
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    if (!(cin >> n) || n < 0){
        cout << "Error: Invalid input. Please enter a positive integer." << endl;
        return 1;
    }
    cout << "Running sums up to " << n << " are: ";
    for(int i = 1; i <= n; i++){
        int result = runningSum(i);
        if (i > 1) {
            cout << ", ";
        }
        cout << result;
    }
    cout << endl;
    return 0;
}
