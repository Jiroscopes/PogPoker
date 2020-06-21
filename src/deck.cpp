#include "deck.h"
#include "CardComponent.h"
#include "GraphicsComponent.h"
#include "EntityManager.h"
//#include "GameObject.h"

const int Deck::DECK_SIZE = 52;

std::vector<Entity*> deck(Deck::DECK_SIZE);


Deck::Deck(EntityManager* entityManager)
{
    for (int i=0; i<DECK_SIZE; i++) 
    {
		Entity* newCard = new Entity();
		entityManager->addEntity(newCard);
		newCard->addComponent<CardComponent*>(new CardComponent(i));
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

Entity** Deck::deal()
{
	// Move this to player at some point
	Entity** hand = new Entity*[2];

	if (!deck.empty()) {
		hand[0] = deck.back();
		std::string filename = "../assets/cards/";
		CardComponent* cardComp = hand[0]->getComponent<CardComponent*>(1);
		filename.append(cardComp->getFilename());
		hand[0]->addComponent<GraphicsComponent*>(new GraphicsComponent(filename.c_str(), hand[0], 50, 50));
		deck.pop_back();

		hand[1] = deck.back();
		std::string filename2 = "../assets/cards/";
		CardComponent* cardComp2 = hand[1]->getComponent<CardComponent*>(1);
		filename2.append(cardComp->getFilename());
		hand[1]->addComponent<GraphicsComponent*>(new GraphicsComponent(filename2.c_str(), hand[1], 50, 50));
		deck.pop_back();
	}
	else {
		std::cout << "Deck is empty ??" << std::endl;
	}

	return hand;
}

