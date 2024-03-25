#include "C.h"

using namespace alpha;
using namespace beta;

int main() {
    alpha::foo();
    alpha::foo();
    alpha::bar();
    beta::foo();
    beta::bar();
    gamma::cout(2);
    gamma::bar();
}