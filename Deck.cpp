#include "Deck.h"
#include <iostream>
#include <ctime>

using namespace std;

Deck::Deck() {
    numCards = NUM_CARDS;
    topCardIndex = 0;

    char suits[4] = { 'S', 'H', 'D', 'C' };
    char ranks[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i].setCard(ranks[i % 13], suits[i / 13]);
    }
}

void Deck::resetDeck() {
    char suits[4] = { 'S', 'H', 'D', 'C' };
    char ranks[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i].setCard(ranks[i % 13], suits[i / 13]);
    }

    numCards = NUM_CARDS;
    topCardIndex = 0;
}

Card Deck::deal() {
    if (isEmpty()) {
        cout << "Error: deck is empty" << endl;
        return Card();
    }

    Card card = cards[topCardIndex];
    numCards--;
    topCardIndex++;

    return card;
}

void Deck::shuffle() {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    topCardIndex = 0;
}

bool Deck::isEmpty() {
    return numCards == 0;
}

void Deck::show() {
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i].show();
        if (i == NUM_CARDS - 1) {
            cout << "\n\n";
        }
    }
}