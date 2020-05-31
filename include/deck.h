#include "Entity.h"
#include <vector>
#include <ctime>
#include <iostream>

class Deck
{
    public:
        static const int DECK_SIZE;
		std::vector<Entity*> deck;
        Deck();
		~Deck();
        void shuffle();
        Entity* deal();
};
