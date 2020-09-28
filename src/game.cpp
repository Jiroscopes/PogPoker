#include "game.h"
#include "TextureManager.h"
#include "deck.h"
#include "map.h"
#include "table.h"
#include "PlayScene.h"
#include "MainMenu.h"
#include <memory>

EntityManager* Game::entityManager = new EntityManager();
//Deck* startingDeck = nullptr;
//Table* table = nullptr;


//int window_height = 720;
//int window_width = 1280;

SDL_Renderer* Game::renderer = nullptr;
EventManager* Game::eventManager = nullptr;
Easing* Game::easingMan = nullptr;
SceneStateMachine* Game::sceneManager = nullptr;

SDL_Rect cursor;

Game::Game()
{
}

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
			SDL_SetRenderDrawColor(renderer, 0, 0, 95, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	eventManager = new EventManager();
	sceneManager = new SceneStateMachine();
	easingMan = new Easing();

	// Load the play scene
	//PlayScene* play = new PlayScene();
	//MainMenu* mainScene = new MainMenu();
	//sceneManager->addScene(std::make_shared<PlayScene>(*play));
	//sceneManager->addScene(std::make_shared<MainMenu>(*mainScene));
	//sceneManager->switchToScene(0);

	//table = new Table();
	//startingDeck = new Deck(entityManager);
	//startingDeck->shuffle();
	//Card** hand = startingDeck->deal();
}

void Game::handleEvents()
{
	SDL_Event event;
	cursor.h = 80;
	cursor.w = 80;

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
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
			eventManager->update(&event);
			cursor.x = event.motion.x;
			cursor.y = event.motion.y;
			break;
		case SDL_QUIT:
			clean();
			isRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	entityManager->update();
	easingMan->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderSetLogicalSize(renderer, window_width, window_height);
	// add to render
	sceneManager->render(); // render scene map
	//table->render();
	entityManager->render();
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