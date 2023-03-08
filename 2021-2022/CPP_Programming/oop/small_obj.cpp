// demonstrates a small, simple object
#include <iostream>
using namespace std;
// one data member and two member functions
class SmallObj
{
private:
    int data;
public:
    void set_data(int d)
    { this->data = d; }
    void show_data()
    { cout << " Data is " << this -> data << endl; }
};

int main()
{
    SmallObj s1, s2;   //define two objects of class SmallObj
    s1.set_data(1066);  //call member function to set data
    s2.set_data(1776);
    s1.show_data();     //call member function to display data
    s2.show_data();
    return 0;
}