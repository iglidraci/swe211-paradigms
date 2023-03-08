#include <iostream>

using namespace std;
class Base {
public:
    void foo() {
        cout << "Foo from base class\n";
    }
};

class Derived1 : public Base {
public:
    void foo() {
        cout << "Foo from derived class 1\n";
    }
};

class Derived2 : public Base {
public:
    void foo() {
        cout << "Foo from derived class 2\n";
    }
};
