#include <iostream>

using namespace std;

struct t {
    unsigned int e : 1;
    unsigned int a : 32;
};

int main () {
    cout << sizeof(t) << endl;
    t a;
    cout << sizeof(a.a);

}

