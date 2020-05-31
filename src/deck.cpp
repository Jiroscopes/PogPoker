#include "deck.h"
#include "CardComponent.h"
//#include "GameObject.h"

const int Deck::DECK_SIZE = 52;

std::vector<Entity*> deck(Deck::DECK_SIZE);


Deck::Deck()
{
    for (int i=0; i<DECK_SIZE; i++) 
    {
		Entity* newCard = new Entity();
		newCard->addComponent(new CardComponent(i));
		deck.push_back(newCard);
    }
}

Deck::~Deck()
{
	deck.clear();
}

void Deck::shuffle()
{
	srand(time(0));

	for (int i = 0; i < DECK_SIZE; i++)
	{
		int r = i + (rand() % (52 - i));
		std::swap(deck[i], deck[r]);
	}
}

Entity* Deck::deal()
{
	// Move this to player at some point
	Entity* hand[2];

	if (!deck.empty()) {
		hand[0] = deck.back();
		deck.pop_back();

		hand[1] = deck.back();
		deck.pop_back();
	}
	else {
		std::cout << "Deck is empty ??" << std::endl;
	}

	return *hand;
}

