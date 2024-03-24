#include <iostream>

using namespace std;

int c;

int& bar();

int main() {
    c = 10;
    bar() = 5;
    cout << c << endl;
    return 0;
}

int& bar() {
    return c;
}
