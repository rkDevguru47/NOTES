#include <iostream>

using namespace std;

class Box {
private:
    int height;
    int width;

public:
    Box(int h, int w) {
        height = h;
        width = w;
    }

    int getArea() {
        return height * width;
    }

    bool operator>(const Box& other) {
        return this->getArea() > other.getArea();
    }

    bool operator<(const Box& other) {
        return this->getArea() < other.getArea();
    }
};

int main() {
    Box b1(2, 5);
    Box b2(3, 5);

    if (b1 > b2) {
        cout << "Box b1 has a larger area than Box b2." << endl;
    } else {
        cout << "Box b2 has a larger area than Box b1." << endl;
    }

    if (b1 < b2) {
        cout << "Box b1 has a smaller area than Box b2." << endl;
    } else {
        cout << "Box b2 has a smaller area than Box b1." << endl;
    }

    return 0;
}
