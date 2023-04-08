#include <iostream>

using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.) {}
    Distance(int feet, float inches): feet(feet), inches(inches) {}
    void show_distance() const {
        cout << feet << "\' - " << inches << "\"" << endl;
    }
    bool operator < (Distance d) {
        float d1 = feet + inches / 12;
        float d2 = d.feet + d.inches / 12;
        return d1 < d2;
    }
};

int main() {
    Distance d1(10, 9);
    Distance d2(10, 10);
    cout << (d1 < d2) << endl;
    // Look at our String class for overloading the equal to (==) operator
    return 0;
}