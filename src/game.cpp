#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "deck.h"

GameObject* cardOne = NULL;
GameObject* cardTwo = NULL;
GameObject* background = NULL;
GameObject* startButton = NULL;

int window_height = 720;
int window_width = 1280;

Card* hand = NULL;
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

		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_RESIZABLE);

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

	// Game start load BG	
	background = new GameObject("../assets/bg.png", 0, 0, 1080, 1920);
	// Start Button
	startButton = new GameObject("../assets/start.png", 0, 0, 150, 300);

	Deck* deck = new Deck();
	deck->shuffle();
	hand = deck->deal();
	cardOne = hand[0].cardObj;
	cardTwo = hand[1].cardObj;
	std::cout << hand[0].getRank() << hand[0].getSuit() << std::endl;
}

void Game::handleEvents()
{
	SDL_Event event;
	//SDL_PollEvent(&event);

	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				window_height = event.window.data2;
				window_width = event.window.data1;
				std::cout << event.window.data1 << std::endl;
				std::cout << event.window.data2 << std::endl;
				break;
			default:
				break;
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	background->update(0, 0, window_height, window_width);
	startButton->update(0, 0, 150, 300);
	cardOne->update((window_width / 2), (window_height - 200), 274, 188);
	cardTwo->update(((window_width / 2) - 188), (window_height - 200), 274, 188);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderSetLogicalSize(renderer, window_width, window_height);
	// This is where we would add stuff to render
	background->render();
	startButton->render();
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