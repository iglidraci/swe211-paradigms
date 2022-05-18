#include <iostream>

class Aa {
public:
    void show() {cout << "Show from class A" << endl;}
};
class Bb {
public:
    void show() {cout << "Show from class B" << endl;}
};
class Cc : public Aa, public Bb{
};

// diamond-shaped inheritance tree
class D1 {
public:
    void foo() {
        cout << "Foo\n";
    }
};

class D2 : public D1 {};
class D3 : public D1 {};
class D4 : public D2, public D3 {};