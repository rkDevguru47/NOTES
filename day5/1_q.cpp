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
void Display(const Student& student)
{
    cout << "Student Details:" << endl;
    cout << "----------------" << endl;
    cout << "Student Roll Number: " << student.roll << endl;
    cout << "Student ID: " << student.student_id << endl;
    cout << "First Name: " << student.first_name << endl;
    cout << "Last Name: " << student.last_name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Gender: " << student.gender << endl;
    cout << "Branch: " << student.branch << endl;
    cout << "Address: " << student.address << endl;
    cout << "CGPA: " << student.cgpa << endl;
}

// Function to input the details of a student
int Accept(Student& student)
{
    cout << "Enter student details:" << endl;
    cout << "-----------------------" << endl;
    cout << "Enter student roll number: ";
    if(!(cin >> student.roll)){
        cout << "Invalid input, please enter a valid student roll number" << endl;
        return 1;
    }
    cout << "Enter student ID: ";
    if(!(cin >> student.student_id)){
        cout << "Invalid input, please enter a valid student ID" << endl;
        return 1;
    }
    cout << "Enter first name: ";
    if(!(cin >> student.first_name)){
        cout << "Invalid input, please enter a valid first name" << endl;
        return 1;
    }
    cout << "Enter last name: ";
    if(!(cin >> student.last_name)){
        cout << "Invalid input, please enter a valid last name" << endl;
        return 1;
    }
    cout << "Enter age: ";
    if(!(cin >> student.age)){
        cout << "Invalid input, please enter a valid age" << endl;
        return 1;
    }
    cout << "Enter gender (M/F/O): ";
    if(!(cin >> student.gender)){
        cout << "Invalid input, please enter a valid gender" << endl;
        return 1;
    }
    cout << "Enter branch: ";
    if(!(cin >> student.branch)){
        cout << "Invalid input, please enter a valid branch" << endl;
        return 1;
    }
    cout << "Enter address: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, student.address);
    cout << "Enter CGPA: ";
    if((cin >> student.cgpa)){
        cout << "Invalid input, please enter a valid CGPA" << endl;
        return 1;
    }
    return 0;
}

int main()
{
    Student student;
    Accept(student);
    cout << endl;
    Display(student);
    return 0;
}