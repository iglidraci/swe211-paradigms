#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class DFA {
public:
    vector<char> sigma;
    vector<int> states;
    vector<int> final_states;
    int q0; // initial state
    map< tuple<int,char>, int > theta;
    bool is_accepted(string word) {
        int q = q0;
        for (int i = 0; i < word.length(); ++i) {
            tuple<int,char> t(q, word.at(i));
            q = theta[t];
        }
        return find(final_states.begin(), final_states.end(), q) != final_states.end();
    }
};

int main() {
    DFA dfa;
    for (int i = 0; i < 5; ++i) {
        dfa.states.push_back(i);
    }
    dfa.sigma.push_back('a');
    dfa.sigma.push_back('b');
    dfa.q0 = 0;
    for (int i = 0; i < 4; ++i) {
        dfa.final_states.push_back(i);
    }
    dfa.theta[make_tuple(0, 'a')] = 1;
    dfa.theta[make_tuple(0, 'b')] = 0;
    dfa.theta[make_tuple(1, 'a')] = 2;
    dfa.theta[make_tuple(1, 'b')] = 0;
    dfa.theta[make_tuple(2, 'a')] = 2;
    dfa.theta[make_tuple(2, 'b')] = 3;
    dfa.theta[make_tuple(3, 'a')] = 1;
    dfa.theta[make_tuple(3, 'b')] = 4;
    dfa.theta[make_tuple(4, 'a')] = 4;
    dfa.theta[make_tuple(3, 'b')] = 4;
    cout << (dfa.is_accepted("bababaabaabb")) << endl;
    return 0;
}