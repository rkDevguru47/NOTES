// To define Student Structure and perform operations on it

#include<iostream>
#include<string>
using namespace std;

struct Student
{
    int roll;
    string student_id;
    string first_name;
    string last_name;
    int age;
    char gender;
    string branch;
    string address;
    float cgpa;
};

// Function to print the details of a student
void Display(const Student students[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Student Details:" << endl;
        cout << "----------------" << endl;
        cout << "Student Roll Number: " << students[i].roll << endl;
        cout << "Student ID: " << students[i].student_id << endl;
        cout << "First Name: " << students[i].first_name << endl;
        cout << "Last Name: " << students[i].last_name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Gender: " << students[i].gender << endl;
        cout << "Branch: " << students[i].branch << endl;
        cout << "Address: " << students[i].address << endl;
        cout << "CGPA: " << students[i].cgpa << endl;
        cout << "----------------" << endl;
    }
}

// Function to input the details of students
void Accept(Student students[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Enter student roll number: ";
        while (!(cin >> students[i].roll)) {
            cout << "Invalid input, please enter a valid student roll number: ";
            cin.clear();
            cin.ignore();
        }
        cout << "Enter student ID: ";
        cin >> students[i].student_id;
        cout << "Enter first name: ";
        cin >> students[i].first_name;
        cout << "Enter last name: ";
        cin >> students[i].last_name;
        cout << "Enter age: ";
        while (!(cin >> students[i].age)) {
            cout << "Invalid input, please enter a valid age: ";
            cin.clear();
            cin.ignore();
        }
        cout << "Enter gender (M/F/O): ";
        cin >> students[i].gender;
        cout << "Enter branch: ";
        cin >> students[i].branch;
        cout << "Enter address: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, students[i].address);
        cout << "Enter CGPA: ";
        while (!(cin >> students[i].cgpa)) {
            cout << "Invalid input, please enter a valid CGPA: ";
            cin.clear();
            cin.ignore();
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input, please enter a valid number of students" << endl;
        return 1;
    }

    Student* students = new Student[n];
    Accept(students, n);
    cout << endl;
    Display(students, n);
    delete[] students;
    return 0;
}