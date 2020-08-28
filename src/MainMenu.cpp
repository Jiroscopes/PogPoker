#include "MainMenu.h"
//#include "EntityManager.h"
#include "Game.h"

MainMenu::MainMenu() 
{

}

void MainMenu::onCreate() 
{
	// Create some menu options
	MenuOption* playButton = new MenuOption(0, "../assets/play.png", { 1 * 80, 3 * 80 });
	MenuOption* exitButton = new MenuOption(0, "../assets/exit.png", { 1 * 80, 4 * 80 });

	// Load the options into the render/update pipeline
	Game::entityManager->addEntity(exitButton);
	Game::entityManager->addEntity(playButton);

	loadEntityIntoVectors(exitButton);
	loadEntityIntoVectors(playButton);

	// Create the bg
	map = new Map(1280, 720, "../assets/map-tilest.png", false);
}

void MainMenu::onDestroy() {}

void MainMenu::onActivate() 
{
	// add things to render/update pipeline
	for (GraphicsComponent* gfxComponent : sceneEntitiesGraphics)
	{
		gfxComponent->setRenderFlag(true);
	}
}

void MainMenu::onDeactivate() 
{
	for (Entity* ent : sceneEntities)
	{
		Game::entityManager->removeEntity(ent);
		Game::eventManager->removeEvent(ent->getComponent<EventComponent*>(4));
	}
}

void MainMenu::loadEntityIntoVectors(Entity* ent)
{
	sceneEntitiesGraphics.push_back(ent->getComponent<GraphicsComponent*>(2));
	sceneEntities.push_back(ent);
}

void MainMenu::renderMap()
{
	map->draw();
}
