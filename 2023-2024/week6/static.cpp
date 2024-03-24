// static.cpp
// demonstrates static variables
#include <iostream>
using namespace std;
float get_avg(float);
int main()
{
    float data = 1, avg;
    while (data != 0)
    {
        cout << "Enter a number : ";
        cin >> data;
        avg = get_avg(data);
        cout << "New average is " << avg << endl;
    }
    return 0;
}
//--------------------------------------------------------------
// finds average of old plus new data
float get_avg(float new_data)
{
    static float total = 0; // static variables are initialized
    static int count = 0;   //   only once per program
    count++;
    total += new_data;
    return total / count;
}
