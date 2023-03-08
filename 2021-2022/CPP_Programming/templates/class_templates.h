#include <iostream>
#define MAX 100

template <class T> class GenericStack {
private:
    T data[MAX];
    int top;
public:
    GenericStack() : top(0) {}
    void push (T value) {
        if (top == MAX) {
            std::cout << "Stack is full\n";
            exit(1);
        }
        this -> data[top++] = value;
    }
    bool is_empty() {
        return this -> top == 0;
    }
    T peek() {
        if (is_empty()) {
            std::cout << "Stack is empty\n";
            exit(1);
        }
        return data[top-1];
    }
    T pop() {
        if (is_empty()) {
            std::cout << "Stack is empty\n";
            exit(1);
        }
        return data[--top];
    }
};


/* member functions will be defined externally */
template<class T> class Stack2 {
private:
    T data[MAX];
    int top;
public:
    Stack2();
    void push(T el);
    T pop();
};

template<class T> Stack2<T> ::Stack2() {
    this -> top = 0;
}

template<class T> void Stack2<T> :: push(T el) {
    if (top == MAX) {
        std::cout << "Stack is full\n";
        exit(1);
    }
    this -> data[top++] = el;
}

template<class T> T Stack2<T> ::pop() {
    if (this -> top == 0) {
        std::cout << "Stack is empty\n";
        exit(1);
    }
    return data[--top];
}