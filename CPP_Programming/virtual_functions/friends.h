#include <iostream>

using namespace std;

class beta; // just declaration
class alpha;
class gamma;
class theta;


class alpha {
private:
    int data;
public:
    alpha() : data(1) {}
    friend int some_friend_func(alpha, beta);
};



class beta {
private:
    int data;
public:
    beta() : data(2) {}
    friend int some_friend_func(alpha, beta);
};

/*
 * We want the function some_friend_func() to have access to both of these private data members,
 * so we make it a friend function. It’s declared with the friend keyword in both classes
 * */

int some_friend_func(alpha a, beta b) {
    return a.data + b.data;
}

/*
 * friend class
 * The member functions of a class can all be made friends
 * at the same time when you make the entire class a friend
 * */

class theta {
private:
    int data;
public:
    theta() : data(100) {}
    friend class gamma;
};

class gamma {
private:
    static int total;
public:
    gamma() {total++;}
    ~gamma(){total--;}
    int foo (theta t) {
        return 1 + t.data;
    }
    static int get_total() {
        return total;
    };
};

int gamma::total = 0; //definition of total

