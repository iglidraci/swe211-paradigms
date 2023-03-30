#include <iostream>

using namespace std;

int main() {
    const float PI = 3.14159;
    float rad;
    cout << "enter the radius: ";
    cin >> rad;
    float area = PI * rad * rad;
    cout << "area is " << area << endl;
    return 0;
}