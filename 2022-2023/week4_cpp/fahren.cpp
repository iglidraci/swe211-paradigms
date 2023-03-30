#include <iostream>

using namespace std;

int main() {
    cout << "Enter the temperature in fahrenheit: ";
    int f_temp;
    cin >> f_temp; // >> is the extraction or get from operator
    int c_temp = (f_temp - 32) * 5 / 9;
    cout << "temperature in celsius: " << c_temp << endl;
    return 0;
}