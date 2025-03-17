#ifndef ___STUDENT_H__
#define ___STUDENT_H__

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;

    void Accept(Student students[], int n);
    void Display(Student students[], int n);
};
bool compareByRollNo(const Student& s1, const Student& s2);
void sortByRollNo(Student students[], int n);

#endif 
