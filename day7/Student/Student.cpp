#include "Student.h"
#include <algorithm>

using namespace std;

void Student::Accept(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter roll number and name for student " << i + 1 << ": ";
        cin >> students[i].rollNo >> students[i].name;
    }
}

void Student::Display(Student students[], int n) {
    cout << "Student Data:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Roll Number: " << students[i].rollNo << ", Name: " << students[i].name << endl;
    }
}

bool compareByRollNo(const Student& s1, const Student& s2) {
    return s1.rollNo < s2.rollNo;
}

void sortByRollNo(Student students[], int n) {
    sort(students, students + n, compareByRollNo);
}
