#include <iostream>

// tests non-virtual and virtual destructors

using namespace std;

/**
 * Base class destructors should always be virtual
 * If is not virtual, then it will cause only the base part of the object to be destroyed
 */

class Base {
public:
//    ~Base() // non-virtual destructor
    virtual ~Base() // virtual destructor
    {
        cout << "Base destroyed" << endl;
    }
};

class Derv : public Base {
public:
    ~Derv() {
        cout << "Derived destroyed" << endl;
    }
};

int main()
{
    Base* pBase = new Derv;
    delete pBase;
    return 0;
}