#include <iostream>

class omega {
private:
    unsigned int gender : 1;
public:
    omega() : gender(0) {}
    omega(unsigned int g) : gender(g) {}
    void show() const {
        std::cout << gender << "\n";
    }
    void switch_gender () {
        gender++;
    }
    omega operator = (omega& a) { //overloads the = operator
        std::cout << "Assignment operator used\n";
        return omega(a.gender);
    }
};

/* how to prohibit copying */
class delta {
private:
    delta operator = (delta& d); // private assignment operator
    delta(delta&);
public:
    delta() {}
};
