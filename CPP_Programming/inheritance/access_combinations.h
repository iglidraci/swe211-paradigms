// test publicly and privately derived classes

#include <iostream>
using namespace std;

class A {
private:
    int privDataA;
protected:
    int protDataA;
public:
    int pubDataA;
}; // base class

class B : public A { // publicly-derived class
public:
    void foo() {
        int a;
        // a = privDataA; // not accessible
        a = protDataA;
        a = pubDataA;
    }
};

class C : private A { // privately-derived class
public:
    void foo() {
        int a;
        // a = privDataA; // not accessible
        a = protDataA;
        a = pubDataA;
    }
};
