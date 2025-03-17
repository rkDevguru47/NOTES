#include "Student.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];

    students->Accept(students, n);
    students->Display(students, n);

    sortByRollNo(students, n);
    cout << "Sorted by roll number:" << endl;
    students->Display(students, n);

    return 0;
}
