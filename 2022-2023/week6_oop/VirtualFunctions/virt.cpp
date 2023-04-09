#include <iostream>

using namespace std;

class Base {
public:
    virtual void show() {cout << "Base" << endl;}
};

class Derv1 : public Base {
public:
    void show() {
        cout << "Derived class 1" << endl;
    }
};

class Derv2 : public Base {
public:
    void show() {
        cout << "Derived class 2" << endl;
    }
};

int main() {
    Derv1 dv1;
    Derv2 dv2;
    Base* ptr; // pointer to base class
    ptr = &dv1;
    ptr->show(); // the member functions of the derived classes, not the base class, are executed
    ptr = &dv2;
    ptr->show();
    return 0;
}