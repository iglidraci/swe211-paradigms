#include <iostream>

using namespace std;

class SafeArray {
private:
    static const int CAPACITY = 100;
    int data[CAPACITY];
public:
//    void put(int i, int element) {
//        if (i >= 0 && i <= CAPACITY - 1) {
//            data[i] = element;
//        } else {
//            cout << "Overflow error" << endl;
//            exit(1);
//        }
//    }
//    int get(int i) {
//        if (i >= 0 && i <= CAPACITY - 1) {
//            return data[i];
//        } else {
//            cout << "Overflow error" << endl;
//            exit(1);
//        }
//    }
//    int& access(int i) { // note: return by reference
//        if (i >= 0 && i <= CAPACITY - 1) {
//            return data[i];
//        } else {
//            cout << "Overflow error" << endl;
//            exit(1);
//        }
//    }
    int& operator [] (int i) {
        // uses overloaded [] operator for both put and get
        if (i < 0 || i > 99) {
            cout << "Overflow error"<<endl;
            exit(1);
        }
        return data[i];
    }
};

int main() {
    SafeArray arr;
    for (int i = 0; i < 10; ++i) {
        arr[i] = i * 10;
//        arr.access(i) = i * 10; //*left* side of equal sign
//        arr.put(i, i * 10);
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr[i];
//        cout << arr.access(i);
//        cout << arr.get(i);
    }
    arr[100] = 0;
//    arr.access(100) = 1;
//    arr.put(100, 100);
    return 0;
}