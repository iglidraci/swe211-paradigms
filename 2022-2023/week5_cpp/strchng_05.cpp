#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "There's room for everyone at the rendezvous of victory.";
    string s2 = "not ";
    s1.erase(s1.length() - 1, 1); // remove '.'
    s1.insert(8, s2); // insert 'not'
    s1.append(3, '!'); // append "!!!"
    s1.append(" --- Aime Cesaire");
    cout << s1 << endl;
    int x = s1.find(' ');
    while (x != -1) {
        s1.replace(x, 1, "/");
        x = s1.find(' ');
    }
    cout << "s1 " << s1  << endl;
    s1.erase(s1.find("not"), 3);

    // one char at a time
    for (int i = 0; i < s1.length(); ++i) {
        cout << s1.at(i) << " ";
    }
    cout << endl;
    char word[s1.length() + 1];
    s1.copy(word, s1.length(), 0);
    word[s1.length()] = '\0';
    cout << "Array of chars contains: " << word << endl;
    return 0;
}