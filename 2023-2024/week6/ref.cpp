// demonstrate pass by reference in a function
#include <iostream>

using namespace std;

// finds integer and fractional parts of a real number
void int_frac(float, int&, float&);

int main() {
    float nr, frac_p;
    int int_p;
    do {
        cout << "enter a number: ";
        cin >> nr;
        int_frac(nr, int_p, frac_p);
        cout << "integer part is " << int_p << ", fractional part is " << frac_p << endl;
    } while (nr != 0.0); // stop when number is 0
    return 0;
}


void int_frac(float n, int& int_part, float& frac_part)
{
    /*
     * int_part and int_p are different names for the same place in memory
     */
    int_part = static_cast<int>(n);  //convert to int,
    frac_part = n - int_part; //subtract integer part
}