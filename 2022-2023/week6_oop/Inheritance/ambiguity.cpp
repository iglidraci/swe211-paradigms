#include <iostream>

using namespace std;

/**
* Two base classes have functions with the same name, while a class derived from both base classes
 * has no function with this name.
 * How do objects of the derived class access the correct base class function?
*/
class Alpha {
public:
    void foo() {cout << "Class Alpha" << endl;}
};

class Beta {
public:
    void foo() {cout << "Class Beta" << endl;}
};

class Gamma : public Alpha, public Beta {

};

/**
 * Diamond problem
 * Classes B and C are both derived from class A, and class D is derived by multiple inheritance from both B and C.
 * Trouble starts if you try to access a member function in class A from an object of class D
 * The compiler signals an error.
 */
class A
{
public:
    void foo() {cout << "Foo" << endl;};
};
class B : public A
{  };
class C : public A
{  };
class D : public B, public C
{  };

int main() {
    Gamma obj;
    // obj.foo(); // ambiguous, won't compile
    obj.Alpha::foo(); // disambiguation
    obj.Beta::foo();
    D objD;
    // objD.foo(); //ambiguous: won’t compile
    return 0;
}