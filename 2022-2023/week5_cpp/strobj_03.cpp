#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "atoms";
    string s2 = "void";
    string s3;
    s3 = s1; // assign
    cout << "s3 = " << s3 << endl;
    s3 = s1 + " and " + s2;
    cout << "s3 = " << s3 << endl;
    cout << "Length of " << s1 << ": " << s1.length() << endl;
    s1.swap(s2);
    cout << s1 + " and " + s2 << endl;
    return 0;
}