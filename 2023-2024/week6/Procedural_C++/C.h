#include <iostream>

/**
 * A namespace is a declarative region that provides a scope to the identifiers (functions, variables, etc) inside it.
 * Namespaces are used to organize code into logical groups and to prevent name collisions that can occur
 * especially when your code base includes multiple libraries
 */

int y = 10;

namespace alpha {
    int x = 1;
    void foo() {
        std::cout << "Value of x: " << x << std::endl;
    }
    void bar() {
        std::cout << "Value of y: " << y << std::endl;
    }
}

namespace beta {
    int x = 2;
    void foo() {
        std::cout << "Value of x: " << x << std::endl;
    }
    void bar() {
        y += 10;
        std::cout << "Value of y: " << y << std::endl;
    }
}


namespace {
    void baz() {
        std::cout << "baz" << std::endl;
    }
}

namespace gamma {
    void cout(int x) {
        std::cout << x << std::endl;
        baz();
    }
    void bar() {
        std::cout << "Value of y: " << y << std::endl;
    }
}