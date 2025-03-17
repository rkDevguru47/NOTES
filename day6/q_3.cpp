#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
    int rollNo;
    string name;
    const int D_M; // Constant data member

public:
    // Default constructor
    Student() : D_M(0) {
        cout << "Default constructor called. This pointer: " << this << endl;
    }

    // Parameterized constructor
    Student(int rollNo, string name, int d_m) : rollNo(rollNo), name(name), D_M(d_m) {
        cout << "Parameterized constructor called. This pointer: " << this << endl;
    }

    // Accept function
    void Accept() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, name);
    }

    // Display function
    void Display() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "D_M: " << D_M << endl;
    }
    int GetRollNo() const {
        return rollNo;
    }
    Student& operator=(const Student& other) {
        if (this != &other) {
            rollNo = other.rollNo;
            name = other.name;
            // D_M is a const member, so it cannot be assigned
        }
        return *this;
    }
};

bool compareByRollNo(const Student& a, const Student& b) {
    return a.GetRollNo() < b.GetRollNo();
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    if (!(cin >> n) || n < 1) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    // Create student objects using new operator
    Student* students = new Student[n];

    // Call the Accept function for each student
    for (int i = 0; i < n; i++) {
        students[i].Accept();
    }

    // Sort students by roll number
    stable_sort(students, students + n, compareByRollNo);

    // Create a student object using the parameterized constructor
    Student s(101, "John Doe", 10);
    s.Display();

    // Display all student details
    cout << endl << "Student Details:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].Display();
        cout << endl;
    }

    delete[] students;
    return 0;
}
