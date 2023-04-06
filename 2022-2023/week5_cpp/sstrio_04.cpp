#include <iostream>
#include <string>

using namespace std;

int main() {
    string full_name, address, nickname;
    string greeting = "hello, ";
    cout << "enter the full name:";
    getline(cin, full_name); //reads embedded blanks
    cout << "enter your nickname:";
    cin >> nickname; // 1 word
    greeting += nickname;
    cout << greeting << endl;
    cout << "enter your address on separate lines" << endl;
    cout << "make sure to terminate with '$'";
    getline(cin, address, '$'); // reads multiple lines
    cout << "your address is " << address << endl;
    return 0;
}
