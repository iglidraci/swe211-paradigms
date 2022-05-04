#include <iostream>
using namespace std;

// use parts inventory to demonstrate structures
struct part {
    int model_number;
    int part_number;
    float cost;
};

struct Distance {
    int feet;
    float inches;
};

struct Room {
    Distance length;
    Distance width;
};

void print_part(part);

int main() {
    part part1;
    part1.model_number = 1;
    part1.part_number = 2;
    part1.cost = 200.5F;
    part part2 = {2, 3, 400.F};
    print_part(part1);
    print_part(part2);
    Room dining; // define a Room type
    dining.length.feet = 12;
    dining.length.inches = 6.5;
    dining.width.feet = 10;
    dining.width.inches = 1.5;
    cout << "Dining room area is " << dining.width.feet * dining.length.feet << " square feet\n";
    part part3 = part2;
    part3.cost = 500.F;
    cout << "Part 2 cost is " << part2.cost << " while part 3 cost is " << part3.cost << "\n";
    return 0;
}

void print_part(part p) {
    cout << "Model " << p.model_number << " , part " << p.part_number
         << ", cost $" << p.cost << endl;
}
