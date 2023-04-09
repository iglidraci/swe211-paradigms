#include <iostream>

using namespace std;

// friend classes, allow access to private data

class Alpha {
private:
    int data;
public:
    Alpha(): data(10) {}
    friend class Beta;
};

class Beta {
public:
    void func(Alpha a) {cout << a.data << endl;}
};

int main() {
    Alpha a;
    Beta b;
    b.func(a);
    return 0;
}