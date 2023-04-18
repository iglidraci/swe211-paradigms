#include <iostream>

using namespace std;

class SafeArray {
private:
    int size;
    int* data;
//    int data[size];
public:
    SafeArray(int s): size(s) {
        data = (int*) calloc(size, sizeof(int));
    }
    int& operator [] (int i) {
        if(i < 0 || i >= size) {
            cout << "Index out of bounds" << endl;
            exit(1);
        }
        return data[i];
    }
    SafeArray operator + (SafeArray other) {
        int new_size = size + other.size;
        SafeArray concat(new_size);
        for (int i = 0; i < size; ++i) {
            concat[i] = data[i];
        }
        for (int i = 0; i < other.size; ++i) {
            concat[size+i] = other[i];
        }
        return concat;
    }
    int length() const {
        return size;
    }
};

template<class T> class TempArray {
private:
    int size;
    T* data;
public:
    TempArray(int s): size(s) {
        data = (T*)calloc(size, sizeof(T));
    }
    T& operator [] (int i) {
        if(i < 0 || i >= size) {
            cout << "Index out of bounds" << endl;
            exit(1);
        }
        return data[i];
    }
    int length() {
        return size;
    }
};

int main() {
    SafeArray arr(10);
    for (int i = 0; i < arr.length(); ++i) {
        arr[i] = i * 10;
        cout << arr[i] << " ";
    }
    SafeArray arr2(5);
    for (int i = 0; i < 5; ++i) {
        arr2[i] = i*5;
        cout << arr2[i] << " ";
    }
    cout << endl;
    SafeArray arr3 = arr + arr2;
    for (int i = 0; i < arr3.length(); ++i) {
        cout << arr3[i] << " ";
    }
//    arr[5] = 10;
//    TempArray<string> arr2(5);
//    for (int i = 0; i < 5; ++i) {
//        arr2[i] = "hello";
//        cout << arr2[i] << " ";
//    }
//    TempArray<int> arr3(10);
//    for (int i = 0; i < 10; ++i) {
//        arr3[i] = i * 10;
//        cout << arr3[i] << " ";
//    }

    return 0;
}