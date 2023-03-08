#include <iostream>

using namespace std;
class ABC { // abstract class
public:
    virtual void bar() = 0; // pure virtual function
    virtual void foo() {
        cout << "Foo from ABC\n";
    }
    // abstract class destructor should always be virtual
    virtual ~ABC() {
        cout << "ABC destructor\n";
    }
};

class A1 : public ABC {
public:
    void bar() override { // override annotation
        cout << "bar from A1\n";
    }
    ~A1() override {
        cout << "A1 destructor\n";
    }
};