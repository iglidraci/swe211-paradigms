#include <iostream>
using namespace std;

class Part {
private:
    int model_number;
    int part_number;
    float cost;
public:
    void set_part(int model_number, int part_number, float cost) {
        this -> model_number = model_number;
        this -> part_number = part_number;
        this -> cost = cost;
    }
    void show_part() {
        cout << "Model " << model_number << " , part " << part_number << " and cost $" << cost << endl;
    }
};

class Counter {
private:
    unsigned int count;
public:
    // member-initialization list
    // someClass() : m1(7), m2(33), m2(4)
    Counter() : count(0) {/*empty body*/};
    Counter(unsigned int c) : count(c) {};
    // destructor takes no arguments
    ~Counter() {
        cout << "Counter object with current counter " << count << " is being destroyed\n";
    }
    void increment() {
        count++;
    }
    void increment(Counter other) {
        count += other.get_count();
    }
    unsigned int get_count() {
        return count;
    }
    void decrement();
};

// :: scope resolution operator
// It is a way of specifying what class something is associated with
// not defined within the Counter class
// it is only declared inside the class
void Counter::decrement() {
    count--;
}

struct foo {
private:
    int data;
public:
    void func() {
        cout << "Foo func\n";
    }
};

int main()
{
    Part p1;
    p1.set_part(1, 20, 500.5F);
    p1.show_part();
    Counter c1, c2(2);
    c1.increment();
    c2.increment();
    cout << "c1 = " << c1.get_count() << " , c2 = " << c2.get_count() << endl;
    c1.decrement();
    c1.increment(c2);
    cout << "c1 = " << c1.get_count() << " , c2 = " << c2.get_count() << endl;
    Counter c3 = c1;
    c3.decrement();
    cout << "c1 = " << c1.get_count() << " , c3 = " << c3.get_count() << endl;
    return 0;
}
