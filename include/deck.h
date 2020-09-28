#pragma once
#include "Entity.h"
#include "Card.h"
#include "EntityManager.h"
#include <vector>
#include <ctime>
#include <iostream>

class Deck
{
	private:
		EntityManager* entityManager;
    public:
        static const int DECK_SIZE;
		std::vector<Card*> deck;
		Deck(EntityManager* entMan);
		~Deck();
        void shuffle();
        Card** deal();
};
