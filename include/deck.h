#include "card.h"
#include <vector>
#include <ctime>
#include <iostream>

class Deck
{
    public:
        static const int DECK_SIZE;
		std::vector<Card> deck;
        Deck();
        void shuffle();
        Card* deal();
};
