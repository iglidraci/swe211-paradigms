#include <iostream>
#include "string_manip.h"
void foo(int*, int*);
void bar(const int*);
char e_to_zero(char);

using namespace std;
int main() {
    int a = 10;
    int b = 20;
    cout << "Initially a = " << a << " and b = " << b << endl;
    foo(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    int *aPtr = &a;
    bar(aPtr);
    cout << "a = " << a << endl;
    char str[] = "hello universe";
    to_upper_case(str);
    cout << "After to_upper_case call: " << str << endl;
    char str2[sizeof(str)/sizeof(char)];
    copy_string(str, str2);
    cout << "str2: " << str2 << endl;
    format_string(str2, &e_to_zero);
    cout << "after formatting str2: " << str2 << endl;
    return 0;
}

void foo(int *aPtr, int *bPtr) {
      *aPtr = *aPtr ^ *bPtr;
      *bPtr = *aPtr ^ *bPtr;
      *aPtr = *aPtr ^ *bPtr;
}

void bar(const int *ptr) {
    int a = -5;
    ptr = &a;
    cout << "int pointer 'ptr' is pointing to value " << *ptr << endl;
}

char e_to_zero(char c) {
    return (c == 'E' || c == 'e') ? '0' : c;
}