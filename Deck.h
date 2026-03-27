#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
    public:
        Deck(); // Default Constructor.
        void resetDeck();
        Card deal();
        void shuffle();
        bool isEmpty();
        void show();
    private:
        static const int NUM_CARDS = 52;
        int numCards;
        Card cards[NUM_CARDS];
        int topCardIndex;
};

#endif