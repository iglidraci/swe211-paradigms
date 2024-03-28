#include <iostream>

using namespace std;

// increment counter variable with ++ operator
class Counter {
private:
    unsigned int count;
public:
    Counter(): count(0) {}
    Counter(unsigned int c): count(c) {}
    unsigned get_count() const{
        return count;
    }
//    void operator ++() { // increment (prefix)
//        ++count;
//    }

    Counter operator ++() {
        // increment count prefix
        return Counter(++count);
    }
    Counter operator ++(int) {
        /*
         * Increment count (postfix)
         * This int isn’t really an argument, and it doesn't mean integer.
         * It’s simply a signal to the compiler to create the postfix version of the operator.
         */
        return Counter(count++);
    }
};

int main() {
    Counter c1, c2;
    ++c1;
    cout << c1.get_count() << endl;
    c2 = ++c1;
    cout << "c1 -> " << c1.get_count() << ", c2 -> " << c2.get_count() << endl;
    Counter c3 = c2++;
    cout << "c2 -> " << c2.get_count() << ", c3 -> " << c3.get_count() << endl;
    return 0;
}