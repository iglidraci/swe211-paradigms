#include <iostream>

int y = 10;

namespace A {
    int x = 1;
    void foo() {
        std::cout << "Value of x: " << x << std::endl;
    }
    void bar() {
        std::cout << "Value of y: " << y << std::endl;
    }
}

namespace B {
    int x = 2;
    void foo() {
        std::cout << "Value of x: " << x << std::endl;
    }
    void bar() {
        y += 10;
        std::cout << "Value of y: " << y << std::endl;
    }
}

namespace C {
    void cout(int x) {
        std::cout << x << std::endl;
    }
    void bar() {
        std::cout << "Value of y: " << y << std::endl;
    }
}
