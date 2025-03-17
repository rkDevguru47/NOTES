#include<iostream>
using namespace std;

// Function to calculate the area of a circle
double calculateCircleArea(double radius)
{
    const double pi = 3.14159265358979323846;
    return pi * radius * radius;
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width)
{
    return length * width;
}

// Function to calculate the area of a square
double calculateSquareArea(double side)
{
    return side * side;
}

int main()
{
    int choice;
    double radius, length, width, side;
    do 
    {
        // Display the menu
        cout << "1. Calculate the area of a circle" << endl;
        cout << "2. Calculate the area of a rectangle" << endl;
        cout << "3. Calculate the area of a square" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        // Handle the user's choice
        switch (choice)
        {
            case 1: {
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                cout << "The area of the circle is: " << calculateCircleArea(radius) << endl;
                break;
            }
            case 2: {
                cout << "Enter the length and width of the rectangle: ";
                cin >> length >> width;
                cout << "The area of the rectangle is: " << calculateRectangleArea(length, width) << endl;
                break;
            }
            case 3: {
                cout << "Enter the side length of the square: ";
                cin >> side;
                cout << "The area of the square is: " << calculateSquareArea(side) << endl;
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        cout << endl;
    } while(choice != 4);
    return 0;
}
