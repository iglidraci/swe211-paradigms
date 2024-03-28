#include <iostream>

using namespace std;

class Bar {
private:
    static int objects; // note: “declaration” only!
public:
    Bar() {
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
int Bar::objects = 0; //*definition* of variable 'objects'

int main() {
    Bar b1, b2, b3;
    cout << "Total number of Bar objects " << Bar::get_objects() << endl;
}