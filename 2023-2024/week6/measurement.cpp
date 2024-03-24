#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inches;
};

struct Room
{
    Distance width;
    Distance length;
};

float room_area(Room);

Distance add_distances(Distance, Distance);

void print_distance(Distance);
void print_distance(float); // method overloading

int main()
{
    Room dining;
    dining.length.feet = 13;
    dining.length.inches = 6.5;
    dining.width.feet = 10;
    dining.width.inches = 0.0;
    float area = room_area(dining);
    // find area and display it
    cout << "Dining room area is " << area
         << " square feet\n";
    Room laundry_room = {{13, 6.5}, {10, 0.0}};
    cout << "Laundry room area is " << room_area(laundry_room) << endl;
    print_distance(laundry_room.length);
    print_distance(laundry_room.width);
    return 0;
}

float room_area(Room room)
{
    float l = room.length.feet + room.length.inches / 12;
    float w = room.width.feet + room.width.inches / 12;
    return l * w;
}

Distance add_distances(Distance d1, Distance d2)
{
    Distance d = {d1.feet + d2.feet, d1.inches + d2.inches};
    if (d.inches >= 12.)
    {
        d.inches -= 12;
        d.feet++;
    }
    return d;
}

void print_distance(Distance d)
{
    cout << d.feet << "'" << d.inches << "\"" << endl;
}

void print_distance(float dd) // parameter dd of type float
{
    int feet = static_cast<int>(dd / 12);
    float inches = dd - feet * 12;
    cout << feet << "' " << inches << "\"" <<endl;
}
