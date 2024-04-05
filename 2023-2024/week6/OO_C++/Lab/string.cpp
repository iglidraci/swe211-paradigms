#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    const static int CAPACITY = 100;
    char str[CAPACITY];
public:
    String() {
        str[0] = '\0';
    }
    String(char str2[]) {
        if(strlen(str2) < String::CAPACITY)
            strcpy(str, str2);
        else {
            cout << "String overflow" << endl;
            exit(1);
        }
    }

    String operator + (const String s2) const {
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

    bool operator > (String s2) const {
        return strcmp(str, s2.str) > 0;
    }

    char operator [] (int i) {
        if (i < 0 || i >= strlen(str)) {
            cout << "Index out of bounds"<<endl;
            exit(1);
        }
        return str[i];
    }

    void display() {
        cout << str << " (mem = " << &str << ")" << endl;
    }

    explicit operator char*() {
        return str;
    }
};

int main() {
    char s0[] = "Hello";
    String s1 = s0;
    String s2 = " World";
    String s3 = s1 + s2;
    s3.display();
    String s4 = "Hello World";
    cout << (s3 == s4) << endl;
    cout << s3[1] << endl;
    char* s6 = static_cast<char*>(s1);
    cout << s6 << endl;
    String s7 = s4;
    s4.display();
    s7.display();
    return 0;
}