#include <iostream>

using namespace std;

int main() {
    const int SIZE = 5;
    float sales[SIZE];
    cout << "enter the sales: ";
    for (int i = 0; i < SIZE; ++i) {
        cin >> sales[i];
    }
    float total = 0;
    for (int i = 0; i < SIZE; ++i) {
        total += sales[i];
    }
    cout << "average " << total/SIZE << endl;
    cout << sales[4] << " " << sales[5] << " " << sales[6];
    return 0;
}