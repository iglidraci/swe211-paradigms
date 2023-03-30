#include <iostream>

using namespace std;

struct part {
    int model_number;
    int part_number;
    float cost;
};

int main() {
    part p1; // define part
    p1.model_number = 1;
    p1.part_number = 1;
    p1.cost = 20.5;
    cout << "Model number: " << p1.model_number << endl;
    cout << "Cost: " << p1.cost << endl;
    part p2 = {2, 2, 10.5};
    cout << "Model number: " << p2.model_number << endl;
    cout << "Cost: " << p2.cost << endl;
    part p3 = p2;
    p3.model_number = 3;
    return 0;
}