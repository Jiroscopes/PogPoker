#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "deck.h"

GameObject* player;
GameObject* cardOne;
GameObject* cardTwo;
Card* hand;
std::vector<GameObject> gameEntities;
SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialized..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
	
	//player = new GameObject("../assets/cards/ace_of_clubs.png", 0, 0);

	Deck* deck = new Deck();
	deck->shuffle();
	hand = deck->deal();
	cardOne = hand[0].cardObj;
	cardTwo = hand[1].cardObj;
	//std::cout << hand[0].getRank() << hand[0].getSuit() << std::endl;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	//player->update();
	cardOne->update();
	cardTwo->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	// This is where we would add stuff to render
	//player->render();
	cardOne->render();
	cardTwo->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned..." << std::endl;
}

bool Game::running()
{
	return Game::isRunning;
}