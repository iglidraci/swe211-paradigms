#include <iostream>

using namespace std;

class Stack1 {
protected:
    static const int MAX = 3;
    int data[MAX];
    int top = 0;
public:
    void push(int element) {
        data[top++] = element;
    }
    int pop() {return data[--top];}
    void print() {
        cout << "TOP [";
        int i = (top >= MAX) ? MAX - 1 : top - 1;
        for(; i>=0; i--) {
            cout << data[i] << ",";
        }
        cout << "] BOTTOM" << endl;
    }
};

// when keyword private is used in inheriting, objects of the derived class
// cannot access public member functions of the base class
// privately derived classes

class Stack2 : public Stack1 {
public:
    void push(int element) {
        if (top >= MAX) {
            cout << "Error: Stack is full" << endl;
            exit(1);
        }
        Stack1::push(element); // call push in super class
    }
    int pop() {
        if (top == 0) {
            cout << "Error: Stack is empty" << endl;
            exit(1);
        }
        return Stack1 :: pop();
    }
};

