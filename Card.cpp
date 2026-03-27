#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card() {
    rank = 'A';
    suit = 'S';
}

Card::Card(char r, char s) {
    rank = r;
    suit = s;
}

void Card::setCard(char r, char s) {
    rank = r;
    suit = s;
}

int Card::getValue() const {
    if (rank == 'A') {
        return 1;
    }
    else if (rank == 'J' || rank == 'Q' || rank == 'K') {
        return 10;
    }
    else {
        return rank - '0';
    }
}

void Card::show() const {
    string rankString;
    string suitSymbol;

    switch (rank) {
    case 'A':
        rankString = "Ace";
        break;
    case '2':
        rankString = "Two";
        break;
    case '3':
        rankString = "Three";
        break;
    case '4':
        rankString = "Four";
        break;
    case '5':
        rankString = "Five";
        break;
    case '6':
        rankString = "Six";
        break;
    case '7':
        rankString = "Seven";
        break;
    case '8':
        rankString = "Eight";
        break;
    case '9':
        rankString = "Nine";
        break;
    case 'T':
        rankString = "Ten";
        break;
    case 'J':
        rankString = "Jack";
        break;
    case 'Q':
        rankString = "Queen";
        break;
    case 'K':
        rankString = "King";
        break;
    default:
        rankString = "";
        break;
    }

    switch (suit) {
    case 'S':
        suitSymbol = "Spades";
        break;
    case 'C':
        suitSymbol = "Clubs";
        break;
    case 'H':
        suitSymbol = "Hearts";
        break;
    case 'D':
        suitSymbol = "Diamonds";
        break;
    default:
        suitSymbol = "";
        break;
    }

    cout << rankString << " of " << suitSymbol << " (" << rank << suit << ")" << endl;
}