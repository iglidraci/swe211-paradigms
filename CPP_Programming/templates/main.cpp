#include <iostream>
#include "temp_funcs.h"
#include "class_templates.h"

using namespace std;

void test_abs();

void test_stack();

int main() {
    test_abs();
    show_kv(1.9, 20);
    test_stack();
    return 0;
}

void test_stack() {
    GenericStack<float> s1;
    s1.push(1.2F);
    s1.push(2.2F);
    cout << s1.pop() << endl;
    Stack2<int> s2;
    for (int i = 0; i < 5; ++i) {
        s2.push(i);
    }
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
}

void test_abs() {
    int int1 = 5;
    int int2 = -6;
    long lon1 = 70000L;
    long lon2 = -80000L;
    double dub1 = 9.95;
    double dub2 = -10.15;
    //calls instantiate functions
    cout << "/abs(" << int1 << ")=" << abs(int1);  //abs(int)
    cout << "/abs(" << int2 << ")=" << abs(int2);  //abs(int)
    cout << "/abs(" << lon1 << ")=" << abs(lon1);  //abs(long)
    cout << "/abs(" << lon2 << ")=" << abs(lon2);  //abs(long)
    cout << endl;
}
