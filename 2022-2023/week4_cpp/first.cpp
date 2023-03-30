/*
 * Preprocessor directive is an instruction to the compiler.
 * A part of the compiler called the preprocessor deals with these directives before it begins the real compilation process
 */
#include <iostream>

/*
 * The using directive
 * C++ program can be divided into different namespaces.
 * A namespace is a part of the program in which certain names are recognized
 * Outside the namespace they’re unknown.
 * std::cout
 */
using namespace std;



int main() {
    /*
     * cout is actually an object, it corresponds to standard output stream
     * operator << is called the insertion or put to operator
     * it redirects the content on the right to the object on the left
     * */
    cout << "hello world\n";
    int a; // declare and define
    a = 1;
    char b = 'b';
    cout << a << " " << b << endl;
    return 0;
}
