#include <iostream>
#include <typeinfo>

// It’s possible to find out information about an object’s class and even change the class of an object at runtime

// Dynamic cast used to test type of object
// For dynamic casts to work, the base class must be polymorphic; that is, it must have at least one virtual function

using namespace std;

class Base {
    virtual void func() {}
};

class Derv1 : public Base {};

class Derv2 : public Base {};

// check if the argument points to a Derv1
bool isDerv1(Base* ptr) {
    /**
     * The dynamic_cast operator attempts to convert this unknown pointer ptr to type Derv1
     * If the result is not null, ptr did point to a Derv1 object
     * If the result is null, it pointed to something else
     */
    return dynamic_cast<Derv1*>(ptr) != nullptr;
}

void display_name(Base* ptr) {
    // You can obtain information about the class name using the typeid operator
    cout << "pointer to an object of " << typeid(*ptr).name() << endl;
}

int main() {
    Derv1* d1 = new Derv1;
    Derv2* d2 = new Derv2;
    if(isDerv1(d1))
        cout << "d1 is a member of the Derv1 class" << endl;
    else
        cout << "d1 is NOT a member of the Derv1 class" << endl;
    if(isDerv1(d2))
        cout << "d2 is a member of the Derv1 class" << endl;
    else
        cout << "d2 is NOT a member of the Derv1 class" << endl;
    display_name(d1);
    display_name(d2);
    return 0;
}