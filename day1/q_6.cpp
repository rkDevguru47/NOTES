#include<iostream>
using namespace std;

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width)
{
    return length * width;
}

int main()
{
    double length, width;
    // Get user input for the length and width of the rectangle
    cout << "Enter the length of the rectangle: ";
    if (!(cin >> length)){
        cout << "Error: Invalid input. Please enter valid length." << endl;
        return 1;
    }
    cout << "Enter the width of the rectangle: ";
    if (!(cin >> width)){
        cout << "Error: Invalid input. Please enter valid width." << endl;
        return 1;
    }
    // Calculate the area of the rectangle
    double area = calculateRectangleArea(length, width);
    // Display the result
    cout << "The area of the rectangle is: " << area << " square units" << endl;
    return 0;
}
