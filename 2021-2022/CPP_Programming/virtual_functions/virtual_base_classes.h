#include <iostream

class Parent {
protected:
    int data;
};

class Child1 : virtual public Parent {};
class Child2 : virtual public Parent{};

class Grandchild : public Child1, public Child2 {
public:
    void print_data() {
        return data;
    }
};

/*
 * The use of the keyword virtual in these two classes causes them to share a
 * single common sub-object of their base class Parent.
 * Since there is only one copy of data, there is no ambiguity when it is referred to in Grandchild
 * */