#include <iostream>

using namespace std;

class Foo {
private:
    static int objects; // note: “declaration” only!
public:
    Foo() {
        objects++;
    }
    static int get_objects() {
        return objects;
    }
};

/*
 * Putting the definition of static member data outside the class serves to emphasize
 * that the memory space for such data is allocated only once.
 * */
int Foo::objects = 0; //*definition* of variable 'objects'


int main() {
    Foo f1, f2, f3;
    cout << "Total number of Foo objects " << Foo::get_objects() << endl;
}