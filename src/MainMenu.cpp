#include "MainMenu.h"
#include "PrettyEnitity.h"
#include "Game.h"
#include "AnimationComponent.h"

MainMenu::MainMenu() 
{

}

void MainMenu::onCreate() 
{
	// Create some menu options
	MenuOption* playButton = new MenuOption(0, "../assets/play.png", { 1 * 80, 4 * 80 });
	MenuOption* exitButton = new MenuOption(1, "../assets/exit.png", { 1 * 80, 5 * 80 });
	PrettyEntity* logo = new PrettyEntity();


	logo->addComponent<PhysicsComponent*>(new PhysicsComponent(logo, { 5 * 80, 0 }, { 400, 320 }));

	GraphicsComponent* gfx = new GraphicsComponent(logo, "../assets/main-menu/logo.png", { 552, 422 });
	logo->addComponent<GraphicsComponent*>(gfx);
	AnimationComponent* animationComp = new AnimationComponent(gfx, 1000, 4);
	logo->addComponent<AnimationComponent*>(animationComp);
	animationComp->startAnimation();

	// Load the options into the render/update pipeline
	Game::entityManager->addEntity(exitButton);
	Game::entityManager->addEntity(playButton);
	Game::entityManager->addEntity(logo);

	loadEntityIntoVectors(exitButton);
	loadEntityIntoVectors(playButton);
	loadEntityIntoVectors(logo);

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
