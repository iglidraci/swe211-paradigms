#include <iostream>
#include <cstring>

using namespace std;
// overloaded ‘+’ operator adds two Distances
class Distance {
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.) {}
    Distance(int feet, float inches): feet(feet), inches(inches) {}
    void show_distance() const {
        cout << feet << "' - " << inches << "\"" << endl;
    }
    Distance operator + (Distance d) const; // add two distances
};

Distance Distance::operator+(Distance d) const {
    int f = feet + d.feet;
    float i = inches + d.inches;
    if ( i >= 12) {
        i -= 12;
        f++;
    }
    return Distance(f, i);
}
int main() {
    Distance d1(2, 10);
    Distance d2 = Distance(1, 11);
    /**
     * The argument on the left side of the operator (d1 in this case) is the object of which the operator is a member.
     * The object on the right side of the operator (d2) must be furnished as an argument to the operator.
     */
    Distance d3 = d1 + d2;
    d3.show_distance();
    Distance d4 = d1 + d2 + d3;
    d4.show_distance();
    return 0;
}