#include <iostream>
#include <string>

/**
* When we will never want to instantiate objects of a base class, we call it an abstract class.
 * Such a class exists only to act as a parent of derived classes that will be used to instantiate objects.
 * How can we create an abstract class?
 * By placing at least one pure virtual function in the base class.
 * A pure virtual function is one with the expression =0 added to the declaration.
*/

using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n): name(n) {}
    string get_name(){return name;}
    virtual bool is_outstanding() = 0; // pure virtual function
};

class Student : public Person {
private:
    float gpa;
public:
    Student(string name, float g): Person(name), gpa(g) {}
    bool is_outstanding() {
        return gpa > 3.5;
    }
};

class Professor : public Person {
private:
    int num_publications;
public:
    Professor(string name, int pub): Person(name), num_publications(pub) {}
    bool is_outstanding() {
        return num_publications >= 100;
    }
};

int main() {
//     Person p; // can’t instantiate objects from abstract class
    Person* people[3]; // array of pointers to Persons
    people[0] = new Student("Foo", 3.4);
    people[1] = new Professor("Bar", 100);
    people[2] = new Student("Baz", 3.6);
    for (int i = 0; i < 3; ++i) {
        cout << (people[i] -> is_outstanding() ? "is outstanding" : "is not outstanding") << endl;
    }
}