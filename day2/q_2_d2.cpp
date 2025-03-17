// Find principle intrest using principal, rate and time
#include<iostream>
using namespace std;

int main()
{
    double principle, rate, time;
    cout << "Enter the principle amount: ";
    if (!(cin >> principle)){
        cout << "Invalid input. Please enter a valid principle amount." << endl;
        return 1;
    }
    cout << "Enter the rate of interest: ";
    if (!(cin >> rate)){
        cout << "Invalid input. Please enter a valid rate of interest." << endl;
        return 1;
    };
    cout << "Enter the time period (in years): ";
    if (!(cin >> time)){
        cout << "Invalid input. Please enter a valid time period." << endl;
        return 1;
    }
    double simpleInterest = (principle * rate * time) / 100;
    cout << "The simple interest is: " << simpleInterest << endl;
    return 0;
}