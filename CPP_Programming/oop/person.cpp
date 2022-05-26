#include <iostream>
#include <stdlib.h>

using namespace std;
/*
 * automatically checks the index numbers you used to access the array,
 * to ensure that they are not out of bounds
 * */
class SafeArray {
private:
    int* data;
    int size;
public:
    SafeArray(int s) {
        data = (int*) calloc(s, sizeof(int));
        size = s;
    }
    // the subscript operator
    int& operator [](int n) const // return by reference
    {
        if( n< 0 || n>=size )
        {
            cout << "Index out of bounds\n";
        }
        return data[n];
    }
    void operator ++() {
        for (int i = 0; i < size; i++)
        {
            data[i]++;
        }
    }
};

void print_safe_array(SafeArray, int);

int main() {
    const int size = 5;
    SafeArray arr(size);
    for (int i=0; i<=size; i++) {
        arr[i] = i*i;
    }
    print_safe_array(arr, size);
    ++arr;
    print_safe_array(arr, size);
}

void print_safe_array(SafeArray arr, int size) {
    cout << "safe array: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}