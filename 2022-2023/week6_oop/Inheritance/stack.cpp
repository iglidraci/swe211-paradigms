#include <iostream>

using namespace std;

class Stack {
protected:
    static const int CAPACITY = 3;
    int data[CAPACITY];
    int top;
public:
    Stack(): top(-1) {}
    void push(int x) {
        data[++top] = x;
    }
    int pop() {
        return data[top--];
    }
};

class SafeStack : public Stack {
public:
    void push(int x) { // derived class function overrides the base class function
        if (top >= CAPACITY) {
            cout << "Stack is full" << endl;
            exit(1);
        }
        Stack::push(x); // super-class call
    }
    int pop() { // derived class function overrides the base class function
        if (top <= -1) {
            cout << "Stack is empty" << endl;
            exit(1);
        }
        return Stack::pop(); // super-class call
    }
};

int main() {
    SafeStack s1;
    s1.push(11);
    s1.push(22);
    s1.push(33);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    return 0;
}