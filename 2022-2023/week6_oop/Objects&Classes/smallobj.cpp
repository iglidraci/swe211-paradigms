#include <iostream>

using namespace std;

class small_obj {
private:
    int data;
public:
    void set_data(int d) {
        data = d;
    }
    void show_data(){
        cout << data << endl;
    }
};

int main() {
    small_obj s1, s2;
    s1.set_data(10);
    s2.set_data(20);
    s1.show_data();
    s2.show_data();
    return 0;
}