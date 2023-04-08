#include <iostream>

using namespace std;

class Distance {
private:
    static const float MTF = 3.280833F;
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.) {} // no-args constructor
    Distance(float meters) { // one-arg constructor, aka conversion constructors.
        float float_feet = MTF * meters;
        feet = int(float_feet);
        inches = 12 * (float_feet - feet); // inches is what is left
    }
    Distance(int feet, float inches): feet(feet), inches(inches) {}
    void show_distance() const {
        cout << feet << "\' - " << inches << "\"" << endl;
    }

    operator float() const { // conversion operator
        // convert Distance to meters
        float frac_feet = inches/12;
        frac_feet += static_cast<float>(feet);
        return frac_feet/MTF; // convert to meters
    }
};

int main() {
    float meters;
    Distance d1 = 10.5f; // users one-arg constructor, convert meters to Distance
    d1.show_distance();
    meters = d1; // users conversion operator, Distance to meters
    cout << "meters = " << meters << endl;
    return 0;
}