#include "deck.h"
#include "Card.h"

#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "EventComponent.h"

const int Deck::DECK_SIZE = 52;

std::vector<Card*> deck(Deck::DECK_SIZE);


Deck::Deck(EntityManager* entMan) : entityManager(entMan)
{
    for (int i=0; i<DECK_SIZE; i++) 
    {
		Card* newCard = new Card(i);
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

Card** Deck::deal()
{
	// Move this to player at some point
	Card** hand = new Card*[2];

	if (!deck.empty()) {
		
		hand[0] = deck.back(); //.at(38)

		std::vector<MouseEvent> events{ MouseMotion, MouseDown };

		// Add the components to the Card
		hand[0]->addComponent<EventComponent*>(new EventComponent(hand[0], events));

		PhysicsComponent* firstHandCardPhysics = new PhysicsComponent(hand[0], { 5 * 80, 7 * 80 }, { 240, 320 });
		
		hand[0]->addComponent<PhysicsComponent*>(firstHandCardPhysics);
		hand[0]->addComponent<GraphicsComponent*>(new GraphicsComponent(hand[0]->getFilename().c_str(), hand[0]));

		// Add the card to our entity manager so that it can handle the rest.
		entityManager->addEntity(hand[0]);

		// Remove the card from the deck
		deck.pop_back();

		hand[1] = deck.back();

		hand[1]->addComponent<PhysicsComponent*>(new PhysicsComponent(hand[1], { 8*80, 7*80}, { 240, 320 }));
		hand[1]->addComponent<GraphicsComponent*>(new GraphicsComponent(hand[1]->getFilename().c_str(), hand[1]));

		entityManager->addEntity(hand[1]);

		deck.pop_back();
	}
	else {
		std::cout << "Deck is empty ??" << std::endl;
	}

	return hand;
}

