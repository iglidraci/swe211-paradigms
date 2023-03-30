#include <iostream>
#include <cmath>

using namespace std;

double find_value(int);

int main() {
    for (int i = 10; i < 21; ++i) {
        double res = find_value(i);
        cout << "result for n " << i << " : " << res << endl;
    }
    return 0;
}

double find_value(int n) {
    double res = 0;
    for (int i = n; i >= 1; i--) {
        res = sqrt(i*i*i + res);
    }
    return res;
}