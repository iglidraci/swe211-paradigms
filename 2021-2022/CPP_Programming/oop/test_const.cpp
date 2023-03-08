#include <iostream>
/*
 * const: on member functions, on member function arguments, and on objects
 * A const member function guarantees that it will never modify any of its class’s member data
 * const Member Function Arguments
 * When an object is declared as const, you can’t modify it
 * */
using namespace std;

class Foo {
private:
    int a;
public:
    Foo(int val) : a(val) {};
    void func() {a = 10;}
    void const_func() const {
        // a = 4;
        cout << "ERROR: can’t modify a member\n";
    }
};

int main () {
    // only const functions can be called from const obj
    const Foo f(2);
    f.const_func();
}
