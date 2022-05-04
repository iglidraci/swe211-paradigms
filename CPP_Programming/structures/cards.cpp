#include <iostream>
using namespace std;
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14

struct card {
    int number; // from 2 to 14 where 11, 12, 13 and 14 represent the jack, queen, king and ace
    int suit; // 0 to 3 representing clubs, diamonds, hearts and spades
};

enum direction {NORTH, SOUTH, EAST, WEST};

int main() {
    card temp, chosen, prize;
    int position;
    card card1 = {7, CLUBS};
    cout << "card 1 is 7 of clubs\n";
    card card2 = {JACK, HEARTS};
    cout << "card 2 is the jack of hearts\n";
    card card3 = {ACE, SPADES};
    cout << "card 3 is the ace of spades\n";
    prize = card3; // copy this card to remember it
    cout << "Swapping card 1 with card 3\n";
    temp = card3; card3 = card1; card1 = temp;
    cout << "Swapping card 2 with card 3\n";
    temp = card3; card3 = card2; card2 = temp;
    cout << "Swapping card 1 with card 2\n";
    temp = card2; card2 = card1; card1 = temp;
    cout << "In which position (1, 2, 3) is the ace of spades? ";
    cin >> position;
    switch (position) {
        case 1: chosen = card1; break;
        case 2: chosen = card2; break;
        case 3: chosen = card3; break;
    }
    if (chosen.number == prize.number && chosen.suit == prize.suit)
        cout << "You win!\n";
    else cout << "You lose\n";
    direction dir1 = SOUTH;
    cout << dir1 << endl;
    if (dir1 == direction::SOUTH) {
        cout << "You're heading south on the right direction\n";
    }
}

