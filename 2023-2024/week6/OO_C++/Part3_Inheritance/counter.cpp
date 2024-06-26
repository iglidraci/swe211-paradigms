#include <iostream>

using namespace std;

class Counter {
protected:
    unsigned int count;
public:
    explicit Counter(unsigned int c): count(c) {} // avoid implicit casting using explicit keyword
    Counter(): count(0) {}
    void operator ++ (){
        count++;
    }
    unsigned int get_count() const {
        return count;
    }
    void reset() {
        count = 0;
    }
};

class CounterDec : public Counter {
public:
    CounterDec(): Counter() {}
    explicit CounterDec(unsigned int c) : Counter(c) {} // calling constructor in the base class
    void operator -- () {
        count--;
    }

    void reset() { // 'override'
        cout << "Counter reset" << endl;
        Counter::reset(); // call method from base class
    }
};

int main() {
    CounterDec cd(4);
    ++cd;
    ++cd;
    --cd;
    cout << cd.get_count() << endl;
}