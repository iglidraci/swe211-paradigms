#include <iostream> //preprocessor directive

using namespace std; // using directive

int main() {
    cout << "Fahrenheit to Celsius converter"<<endl; // insertion operator
    int fTemp;
    cout << "Enter temp in Fahrenheit: ";
    cin >> fTemp; // extraction operator
    int cTemp = (fTemp - 32) * 5 / 9;
    cout << "Equivalent in Celsius is: " << cTemp << endl;
    int a = static_cast<int>(2.4);
    return 0;
}