// memory saving String class
// overload assignment and copy constructor

#include <iostream>
#include <cstring>

using namespace std;

class StrCount {
private:
    int count;
    char* str;
    explicit StrCount(char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        count = 1;
    }
    ~StrCount() {
        cout << "deallocating " << str << " from memory" << endl;
        delete[] str;
    }
    friend class String;
};

class String {
private:
    StrCount* pStrCnt;
public:
    String() {
        pStrCnt = new StrCount("");
    }
    String(char* s) {
        pStrCnt = new StrCount(s);
    }
    String(String& s) { // copy constructor
        pStrCnt = s.pStrCnt;
        pStrCnt->count += 1;
    }
    ~String() {
        if(pStrCnt -> count == 1) // we are its last user
            delete pStrCnt;
        else
            pStrCnt->count -= 1;
    }
    void display() {
        cout << pStrCnt->str;
        cout << " (addr=" << pStrCnt << ")" << endl;
    }

    String& operator = (String& s) { // assignment operator
        if(this == &s) return *this;
        if(pStrCnt->count == 1)
            delete pStrCnt;
        else
            pStrCnt->count -= 1;
        pStrCnt = s.pStrCnt;
        pStrCnt->count += 1;
        return *this;
    }
};

int main() {
    String s1("slowly slowly catchy monkey");
    cout << "s1 = "; s1.display();
    String s2 = s1;
    cout << "s2 = "; s2.display();
    String s3("softly softly catchee monkey");
    s3 = s2;
    cout << "s3 = "; s3.display();
    String s4("hello");
    s4 = s4;
    s4 = s1 = s2;
    s4.display();
}
