#include <iostream>

using namespace std;

template<class T> class Stack {
private:
    static const int CAPACITY = 10;
    T data[CAPACITY];
    int top;
public:
    Stack(): top(-1) {}
    void push(T x) {
        data[++top] = x;
    }
    T pop() {
        return data[top--];
    }
    bool is_empty() {
        return top == -1;
    }
};

int main() {
    Stack<float> s1;
    s1.push(1.3); s1.push(2.5);
    Stack<string> s2;
    s2.push("foo");
    s2.push("bar");
    s2.push("baz");
    while (!s2.is_empty()) cout << s2.pop() << endl;
    return 0;
}