#include "MainMenu.h"
//#include "EntityManager.h"
#include "Game.h"

MainMenu::MainMenu() 
{

}

void MainMenu::onCreate() {
	MenuOption* playButton = new MenuOption(0, "../assets/play.png", { 1 * 80, 3 * 80 });
	MenuOption* exitButton = new MenuOption(0, "../assets/exit.png", { 1 * 80, 4 * 80 });

	menuOptions.push_back(playButton);
	menuOptions.push_back(exitButton);

	Game::entityManager->addEntity(playButton);
	Game::entityManager->addEntity(exitButton);

	map = new Map(1280, 720, "../assets/map-tileset.png", false);
}

void MainMenu::onDestroy() {}

void MainMenu::onActivate() {}

void MainMenu::onDeactivate() {}

void MainMenu::renderMap()
{
	map->draw();
}
