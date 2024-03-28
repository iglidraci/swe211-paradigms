#include <iostream>

using namespace std;

class Faculty {
private:
    string department;
    string name;
public:
    explicit Faculty(string d, string n): department(d), name(n) {}

    void show_faculty_info() {
        cout << name <<  ", department of " << department << endl;
    }
};

class Student {
private:
    string student_id;
public:
    explicit Student(string s_id): student_id(s_id) {}

    void show_student_id() {
        cout << "Student id " << student_id << endl;
    }
};

class TeachingAssistant : private Student, private Faculty {
public:
    TeachingAssistant(string s_id, string d, string n): Student(s_id), Faculty(d, n) {}
    void show_info() {
        Student::show_student_id();
        Faculty::show_faculty_info();
    }
};

int main() {
    TeachingAssistant ta("123", "CEN", "Foo");
    ta.show_info();
    return 0;
}