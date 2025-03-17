#ifndef ___ARRAY_H_
#define ___ARRAY_H_

class Array {
private:
    int size;
    int *arr;

public:
    Array(int n);
    ~Array();
    void accept();
    void display();
    void sorted();
    int findMax();
    int findMin();
};

#endif 
