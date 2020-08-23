#include "MainMenu.h"
//#include "EntityManager.h"
#include "Game.h"
//#include "map.h"

MainMenu::MainMenu() 
{

}

void MainMenu::onCreate() {
	MenuOption* test = new MenuOption(0);
	menuOptions.push_back(test);
	Game::entityManager->addEntity(test);
	//map = new Map(1280, 720, "../assets/map-tileset.png");
}

void MainMenu::onDestroy() {}

void MainMenu::onActivate() {}

void MainMenu::onDeactivate() {}
