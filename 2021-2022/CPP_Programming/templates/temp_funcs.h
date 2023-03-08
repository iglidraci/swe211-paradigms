#include <iostream>

/*
 * This program defines a template version of abs() and then, in main(),
 * invokes this function with different data types to prove that it works
 * */

// this is called function template
// The variable following the keyword class (T in this example) is called the template argument
template <class T> T abs (T a) {
    return (a > 0) ? a : -a;
};

template <class T, class U> void show_kv(T key, U val) {
    std::cout << "key: " << key << ", value: " << val << std::endl;
}