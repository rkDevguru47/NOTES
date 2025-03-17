#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    int rollNo;
    string name;

    public:
    void Accept() 
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, name);
        
    }

    void Display() const
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};


bool compareByRollNo(const Student& a, const Student& b) {
    return a.rollNo < b.rollNo;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    if (!(cin >> n) || n < 1) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    Student* students = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        students[i].Accept();
    }

    // Sort students by roll number
    sort(students, students + n, compareByRollNo);
    cout << "Students sorted by roll number:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].Display();
        cout << "------------------------" << endl;
    }

    delete[] students;
    return 0;
}
