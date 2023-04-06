#include "C.h"

int main() {
    alpha::foo();
    alpha::bar();
    beta::foo();
    beta::bar();
    gamma::cout(2);
    gamma::bar();
    privateFunc();
}