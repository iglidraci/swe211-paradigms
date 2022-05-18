#include <iostream>
#include "not_virtual.h"
#include "virtual.h"
#include "friends.h"
#include "assignment.h"

void test_not_virtual();

void test_virtual();

void test_friends();

void test_assignment();

using namespace std;
int main() {
    // test_not_virtual();
    // test_virtual();
    // test_friends();
    test_assignment();
    return 0;
}

void test_assignment() {
    omega o1;
    // The compiler creates a new object, o2, and copies the data
    // from o1, member by member, into o2
    omega o2 = o1;
    o2.switch_gender();
    o1.show();
    o2.show();
    delta d1;
    // delta d2 = d1; // function is not accessible
}

void test_friends() {
    alpha a; beta b;
    cout << some_friend_func(a, b) << endl;
    gamma g;
    theta t;
    cout << g.foo(t) <<endl;
    gamma g2;
    gamma g3;
    gamma* g4 = new gamma;
    cout << gamma::get_total() << endl;
    delete g4;
    cout << gamma::get_total() << endl;
}

void test_virtual() {
    // ABC abc; // cannot instantiate ABC
    ABC* abcs[2]; // array of pointers to a type ABC
    A1 a11, a12;
    abcs[0]  = &a11;
    abcs[1] = &a12;
    abcs[0] -> bar();
    abcs[0] -> foo();
    abcs[1] -> bar();
    abcs[1] -> foo();
    ABC* a1 = new A1;
    delete a1;
}

void test_not_virtual() {
    Derived1 d1;
    Derived2 d2;
    Base* ptr;
    ptr = &d1;
    ptr -> foo();
    ptr = &d2;
    ptr -> foo();
    /*
     * The compiler ignores the contents of the pointer ptr and chooses
     * the member function that matches the type of the pointer
     * */
}
