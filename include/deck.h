#pragma once
#include "Entity.h"
#include <vector>
#include <ctime>
#include "EntityManager.h"
#include <iostream>

class Deck
{
	private:
		EntityManager* entityManager;
    public:
        static const int DECK_SIZE;
		std::vector<Entity*> deck;
		Deck(EntityManager* entMan);
		~Deck();
        void shuffle();
        Entity** deal();
};
