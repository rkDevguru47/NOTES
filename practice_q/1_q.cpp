#include <iostream>
#include <string>
using namespace std;

class Address {
public:
    string area;
    string city;
    int pincode;

    Address(string a, string c, int p) {
        area = a;
        city = c;
        pincode = p;
    }
};

class Student {
public:
    int rno;
    string name;
    Address permanentAddress;
    Address currentAddress;

    Student(int r, string n, string pa_area, string pa_city, int pa_pincode, string ca_area, string ca_city, int ca_pincode)
        : rno(r), name(n), permanentAddress(pa_area, pa_city, pa_pincode), currentAddress(ca_area, ca_city, ca_pincode) {}
};

int main() {
    Student s1(101, "sweta", "Shivaji Nagar", "Satara", 411009, "Pashan", "Pune", 411003);
    return 0;
}
