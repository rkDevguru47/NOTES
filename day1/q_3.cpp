#include<iostream>
#include<cmath>
using namespace std;

// Function to calculate compound interest
double calculateCompoundInterest(double principal, double rate, double time, int compoundPeriods)
{
    double amount = principal * pow(1 + (rate / compoundPeriods), compoundPeriods * time);
    return amount;
}

// Function to calculate simple interest
double calculateSimpleInterest(double principal, double rate, double time)
{
    return principal * rate * time;
}

// Function to take user input
bool getUserInput(double &principal, double &rate, double &time, int &compoundPeriods) {
    cout << "Enter the principal amount: ";
    if (!(cin >> principal)){
        cout << "Error: Invalid input. Please enter a valid number." << endl;
        return false;
    }
    cout << "Enter the annual interest rate (as a decimal): ";
    if (!(cin >> rate)){
        cout << "Error: Invalid input. Please enter a valid number." << endl;
        return false;
    }
    cout << "Enter the time period (in years): ";
    if (!(cin >> time)){
        cout << "Error: Invalid input. Please enter a valid number." << endl;
        return false;
    }
    cout << "Enter the number of compound periods per year: ";
    if (!(cin >> compoundPeriods)){
        cout << "Error: Invalid input. Please enter a valid number." << endl;
        return false;
    }
    return true;
}

int main() {
    double principal, rate, time;
    int compoundPeriods;
    // Get user input
    if (!getUserInput(principal, rate, time, compoundPeriods)) {
        return 1;
    }
    // Calculate the compound interest
    double compoundInterest = calculateCompoundInterest(principal, rate, time, compoundPeriods);
    // Display the result
    cout << "The final amount after compound interest is (in Rupees): " << compoundInterest << endl;

    // Calculate the simple interest
    double simpleInterest = calculateSimpleInterest(principal, rate, time);
    // Display the result
    cout << "The simple interest is (in Rupees): " << simpleInterest << endl;

    return 0;
}