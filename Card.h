#ifndef CARD_H
#define CARD_H

class Card
{
    public:
        Card(); // Default Constructor.
        Card(char r, char s);
        void setCard(char r, char s);
        int getValue() const;
        void show() const;

    private:
        char rank;
        char suit;
};

#endif