#include <iostream>
#include <cstring>

using namespace std;

class String { // user-defined string type
protected:
    static int const CAPACITY = 100;
    char str[CAPACITY];
public:
    String() {
        strcpy(str, "");
    }
    String(char str2[]) {
        strcpy(str, str2);
    }
    void show() {
        cout << str << endl;
    }
    String operator +(String s2) const {
        String temp;
        if (strlen(str) + strlen(s2.str) < CAPACITY) {
            strcpy(temp.str, str);
            strcat(temp.str, s2.str);
            return temp;
        } else {
            cout << "String overflow" << endl;
            exit(1);
        }
    }

    bool operator == (String s2) const {
        return strcmp(str, s2.str) == 0;
    }

    bool operator < (String s2) const {
        return strcmp(str, s2.str) < 0;
    }

    // the += operator. Recall that this operator combines assignment and addition into one step
    void operator += (String s2) {
        if (strlen(str) + strlen(s2.str) < CAPACITY) {
            strcat(str, s2.str);
        } else {
            cout << "String overflow" << endl;
            exit(1);
        }
    }
};

class PString : public String {
public:
    PString(char str2[]): String(str2) {

    }
    void left(PString s1, int n) {
        // assign the leftmost n characters from s1
        strncpy(str, s1.str, n);
        str[n] = '\0';
    }

    void right(PString s1, int n) {
        // assign the rightmost n characters from s1
        strncpy(str, s1.str + (strlen(s1.str) - n), n);
        str[n] = '\0';
    }

    void mid(PString s1, int s, int n) {
        // assign the middle n characters from s1, starting at character number s
        strncpy(str, s1.str + s, n);
        str[n] = '\0';
    }
};

int main() {
    PString s1 = "Hello";
    PString s2 = "World";
    PString s3 = "ObjectOriented";
    s1.left(s2, 3);
    s1.show();
    s1.right(s2, 2);
    s1.show();
    s1.mid(s3, 6, 3);
    s1.show();
    return 0;
}