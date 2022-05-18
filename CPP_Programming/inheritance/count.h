class Counter {
protected:
    unsigned int count;
public:
    Counter() : count(0) {}
    Counter(int c) : count(c) {}
    unsigned int get_count() const {
        return count;
    }
    Counter operator ++ () {
        return Counter(++count);
    }
}; // end of class Counter

class CounterD : public Counter {
public:
    CounterD() : Counter() {} // no args constructor
    CounterD(int c) : Counter(c) {}
    CounterD operator -- () {
        return CounterD(--count);
    }
}; // derived class CounterD

