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

class String { // user-defined string type
private:
    static int const CAPACITY = 100;
    char str[CAPACITY];
public:
    String() {
        strcpy(str, "");
    }
    String(char str2[]) {
        strcpy(str, str2);
    }
    void show() {
        cout << str << endl;
    }
    String operator +(String s2) const {
        String temp;
        if (strlen(str) + strlen(s2.str) < CAPACITY) {
            strcpy(temp.str, str);
            strcat(temp.str, s2.str);
            return temp;
        } else {
            cout << "String overflow" << endl;
            exit(1);
        }
    }

    bool operator == (String s2) const {
        return strcmp(str, s2.str) == 0;
    }

    bool operator < (String s2) const {
        return strcmp(str, s2.str) < 0;
    }

    // the += operator. Recall that this operator combines assignment and addition into one step
    void operator += (String s2) {
        if (strlen(str) + strlen(s2.str) < CAPACITY) {
            strcat(str, s2.str);
        } else {
            cout << "String overflow" << endl;
            exit(1);
        }
    }
};
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

//    String s1("Hello");
//    String s2 = " World"; // uses constructor 2
//    String s3 = s1 + s2;
//    s3.show();
//    String s4 = "Hello World";
//    String s5 = "World";
//    cout << (s3 == s4) << endl;
//    cout << (s3 < s5) << endl;
//    s5 += s2;
//    s5.show();
    return 0;
}