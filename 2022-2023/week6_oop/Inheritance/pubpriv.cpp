// tests publicly and privately-derived classes
#include <iostream>

using namespace std;

class A {
public:
    int data;
};

class B : public A {

};

class C : private A {

};

int main() {
    B b;
    cout << b.data <<endl;
    C c;
    // cout << c.data << endl; //error: not accessible
    /*
     * Objects of the publicly derived class B can access public members of the base class A,
     * while objects of the privately derived class C cannot.
     * They can only access the public members of their own derived class
     */
    return 0;
}