#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Circle {
private:
    float radius;
    int center_x;
    int center_y;
    string fill_color;
public:
    // initializer list
    Circle(float r, int x, int y, string color): radius(r), center_x(x), center_y(y), fill_color(color) {
    }
    Circle(): radius(1), center_x(0), center_y(0), fill_color("black"){
    }
    float get_area() {
        return M_PI * pow(radius, 2);
    }
    void set_radius(float r) {
        radius = r;
    }
    void paint() {
        cout << "Painting circle with center (" << center_x << ", " << center_y << "), radius " << radius
            << ", and color " << fill_color << endl;
    }
    ~Circle() {
        /**
         * destructors are called automatically when an object is destroyed
         * same name as the constructor but is preceded by a tilde (~)
         * destructors do not have a return value and they take no arguments
         * The most common use of destructors is to deallocate memory that was allocated
         * for the object by the constructor.
         */
        cout << "Destroying circle with center (" << center_x << ", " << center_y << "), radius " << radius
             << ", and color " << fill_color << endl;
    }
};

class Foo{
public:
    int d;
    Foo(int d): d(d) {}
    void passByValue(Foo f);
    void passByPointer(Foo* f);
    void passByReference(Foo& f);
};
// defining member functions outside the class
void Foo::passByValue(Foo f) {
    f.d = 10;
}

void Foo::passByPointer(Foo *f) {
    if(f != nullptr) {
        // dereference it
        f->d = 10;
    }
}

void Foo::passByReference(Foo &f) {
    f.d = 10;
}

int main() {
    Circle c1(2.5, 1, 1, "red");
    Circle c2;
    c1.paint();
    cout << "area of painted c1: " << c1.get_area() << endl;
    c2.paint();
    cout << "area of painted c2: " << c2.get_area() << endl;
    Circle c3 = c1; // default copy constructor
    // This causes the default copy constructor for the Circle class to perform a member-by-member
    // copy of c1 into c3.
    c3.set_radius(10);
    cout << c3.get_area() << " " << c1.get_area() << endl;

    Foo f1(1);
    Foo f2(5);
    f1.passByValue(f2);
    cout << f2.d << endl;
    f2.passByPointer(&f2);
    cout << f2.d << endl;
    return 0;
}