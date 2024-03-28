#include <iostream>

using namespace std;
// Virtual inheritance is a C++ technique that ensures only one copy of a base class's members
// are inherited by derived classes

class Animal {
public:
    void eat() {
        cout << "animal eating ..." << endl;
    }
};

class Bird : public virtual Animal {
public:
    void layEggs() {
        cout << "bird is laying eggs ..." << endl;
    }
};

class FlightlessBird : public virtual Animal {
public:
    void flap() {
        cout << "sorry, lost the ability to fly ..." <<endl;
    }
};

class Penguin : public Bird, public FlightlessBird {

};


int main() {
    Penguin p;
    p.eat();
    p.layEggs();
    p.flap();
    return 0;
}