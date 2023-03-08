#include <iostream>
#include "count.h"
#include "stacks.h"
#include "access_combinations.h"
#include "multiple_inherit.h"
#include "ambiguity.h"

void test_counter();

void test_stack();

void test_access_combinations();

void test_multiple_inheritance();

void ambiguity();

using namespace std;
int main() {
    // test_counter();
    // test_stack();
    // test_access_combinations();
    // test_multiple_inheritance();
    ambiguity();
    return 0;
}

void ambiguity() {
    Cc cc;
    // cc.show(); //ambiguous--will not compile
    cc.Aa::show();
    cc.Bb::show();
    D4 d4;
    // d4.foo(); // won't compile
    // both D2 and D3 contain a copy of foo() inherited from D1
    // the compiler can't decide which copy to use
}

void test_multiple_inheritance() {
    scientist s1;
    laborer l1;
    cout << "Enter data for scientist 1" << endl;
    s1.set_data();
    cout << "Enter data for laborer 1" << endl;
    l1.set_data();
    cout << "Sc1 data" << endl; s1.get_data();
    cout << "Laborer data" << endl; l1.get_data();
    scientist s3 = scientist("foo", 100, "dr", "cambridge", "doctor");
    cout << "Sc3 data" << endl; s3.get_data();
}

void test_access_combinations() {
    int a;
    B objB;
    // a = objB.privDataA; // not accessible
    // a = objB.protDataA; // not accessible
    a = objB.pubDataA; // A is public to B

    C objC;
    // a = objB.privDataA; // not accessible
    // a = objB.protDataA; // not accessible
    // a = objC.pubDataA; // A is private to B
    /*
     * Objects of the publicly derived class B can access public members of the base class A,
     * while objects of the privately derived class C cannot;
     * they can only access the public members of their own derived class
     * */
}

void test_stack() {
    Stack1 s1 = Stack1();
    s1.push(1); s1.push(2);s1.push(3);s1.push(4);
    s1.print();
    s1.pop();s1.pop();s1.pop();s1.pop();
    cout << "Popped " << s1.pop() << endl;
    s1.print();
//    Stack2 s2 = Stack2();
//    s2.push(1); s2.push(2); s2.push(3); s2.push(4);
    Stack1 s3 = Stack2();
    cout << s3.pop() << endl;
}

void test_counter() {
    CounterD c1;
    CounterD c2 = CounterD(2);
    printf("c1=%d and c2=%d\n", c1.get_count(), c2.get_count());
    ++c1; ++c1; --c1; ++c2; ++c2; --c2;
    printf("c1=%d and c2=%d\n", c1.get_count(), c2.get_count());
    CounterD c3 = --c1;
    cout << "c3=" << c3.get_count() << endl;
}
