#include <iostream>
#include <iomanip>

using namespace std;

const int MONTHS = 2;
const int DISTRICT = 2;

void display_sales(float[][MONTHS]);

int main() {
    float sales[DISTRICT][MONTHS];
    for (int d = 0; d < DISTRICT; ++d) {
        for (int m = 0; m < MONTHS; ++m) {
            cout << "Enter sale for district " << d + 1 << " month " << m + 1 << ": ";
            cin >> sales[d][m];
        }
    }
    display_sales(sales);
    return 0;
}

void display_sales(float sales[][MONTHS]) {
    cout << endl << endl;
    for (int d = 0; d < DISTRICT; ++d) {
        cout << "District " << d + 1;
        for (int m = 0; m < MONTHS; ++m) {
            cout << setiosflags(ios::fixed)      // prevents numbers from being printed in exponential format
                 << setiosflags(ios::showpoint)  //always use point
                 << setprecision(2)
                 << setw(10) // used to set the output field width
                 << sales[d][m];
        }
        cout << endl;
    }
}
