#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    a = 1;
    cout << &a << " " << &b << " " << &c << endl;
    int* aPtr = &a;
    cout << &aPtr << " " << &a << endl;
    cout << *aPtr << endl; // dereference operator
    *aPtr = 5;
    cout << a << endl;
    a = 10;
    cout << *aPtr << endl;
    const int* pInt; // is a pointer to constant int
    c = 8;
    int* const constPtrC = &c; // const pointer to int
    const int* const ccPtr = &c; // const pointer to const int
    return 0;
}