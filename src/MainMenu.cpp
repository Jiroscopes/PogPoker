#include "MainMenu.h"
//#include "EntityManager.h"
#include "Game.h"

MainMenu::MainMenu() 
{
	MenuOption* test = new MenuOption(0);
	menuOptions.push_back(test);
	Game::entityManager->addEntity(test);
}

void MainMenu::onActivate() {}

void MainMenu::onDeactivate() {}

void MainMenu::onCreate() {}

void MainMenu::onDestroy() {}