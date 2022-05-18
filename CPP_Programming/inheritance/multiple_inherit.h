#include <iostream>
#include <string>
using namespace std;

class student {
private:
    string school; // name of last school or university
    string degree; // highest degree earned
public:
    student() {}
    student(string s, string d) : school(s), degree(d) {}
    void set_edu() {
        cout << "Enter the name of school or university you last attended: ";
        cin >> school;
        cout << "Enter the highest degree earned: ";
        cin >> degree;
    }
    void get_edu() const {
        cout << "School or university: " << school << endl;
        cout << "Highest degree earned: " << degree << endl;
    }
};

class employee {
private:
    string name;
    unsigned long number; // employee number
public:
    employee() {}
    employee(string n, unsigned long nr) : name(n), number(nr) {}
    void set_data() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your number: ";
        cin >> number;
    }
    void get_data() const {
        cout << "Name: " << name << endl
            << "Number: " <<number << endl;
    }
};

class scientist : private employee, private student {
private:
    string title;
public:
    scientist() {}
    scientist(string name, unsigned long nr, string title, string school, string degree) :
            employee(name, nr), student(school, degree), title(title) {}
    void set_data() {
        employee::set_data();
        cout << "Enter title: "; cin >> title;
        student::set_edu();
    }
    void get_data() {
        employee::get_data();
        cout << "Title: " << title << endl;
        student::get_edu();
    }
};

class laborer : public employee {

};