#include <iostream>

using namespace std;

class Bar{
private:
    int data;
public:
    void non_const_func() { // non-constant member function
        data++; // can change data
    }
    void const_func() const {
        // constant member function
        // guarantees that it will never modify any of its class’s member data
        // data++; // cannot do this, compiler error
    }

    void const_member_arg(const Bar& b) {
        // const member function arguments
        // you don’t want the function to modify it, the argument should be made const in the function declaration
        // b.data = 10; // cannot do this
    }
};

class Baz {
public:
    int data;
    Baz(int d): data(d) {}
    void get_data() {
        cout << "enter data: "; cin >> data;
    }
    void show_data() const {
        cout << "data: " << data << endl;
    }
};

int main() {
    /*
     * When an object is declared as const, you can’t modify it.
     * It follows that you can use only const member functions with it,
     * because they’re the only ones that guarantee not to modify it
    */
    const Baz b1(100);
    // b1.data = 20; // cannot do this
    // b1.get_data(); // cannot do this
    b1.show_data(); // OK
    return 0;
}