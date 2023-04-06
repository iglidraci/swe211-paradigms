#include <iostream>

using namespace std;

void map(int*, int, int (*)(int));

int square(int);

int main() {
    const int size = 5;
    int nrs[size] = {1, 2, 3, 4, 5};
    map(nrs, size, square);
    for(int nr:nrs)
        cout << nr << " ";
    cout << endl;
}

void map(int* arr, int size, int (*mapping_func)(int)) {
    for (int i = 0; i < size; ++i) {
        arr[i] = mapping_func(arr[i]);
    }
}

int square(int a) {
    return a*a;
}