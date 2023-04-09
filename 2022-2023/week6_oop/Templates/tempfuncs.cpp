// tempfuncs.cpp
// template functions used for absolute value and linear searching

#include <iostream>
#include <string>

using namespace std;

template <class T> T absolute(T num) {
    return (num >= 0 ? num : -num);
}

template<class T> int find(T* arr, T key, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int a = -2;
    long b = 3;
    double c = -4.5;
    cout << absolute(a) << " " << absolute(b) << " " << absolute(c) << endl;
    string names[] = {"foo", "bar", "baz"};
    char grades[] = {'A', 'B', 'A', 'C'};
    cout << find(grades, 'a', 4) << endl;
    string key = "foo";
    cout << find(names, key, 3) << endl;
    return 0;
}