#include "PlayScene.h"
#include "game.h"

void PlayScene::loadEntityIntoVectors(Entity* ent)
{
	sceneEntitiesGraphics.push_back(ent->getComponent<GraphicsComponent*>(2));
	sceneEntities.push_back(ent);
}

PlayScene::PlayScene() : deck(0), map(0) {}

void PlayScene::onCreate()
{
	// load all entities for the scene
	map = new Map(1280, 720, "../assets/map-tileset.png");
	deck = new Deck(Game::entityManager);
	deck->shuffle();
	Card** hand = deck->deal();
	
	loadEntityIntoVectors(hand[0]);
	loadEntityIntoVectors(hand[1]);
}

void PlayScene::onActivate() 
{
	// add things to render/update pipeline
	for (GraphicsComponent* gfxComponent : sceneEntitiesGraphics)
	{
		gfxComponent->setRenderFlag(true);
	}
}	

void PlayScene::onDeactivate()
{
	// remove things from render/update pipeline
	for (GraphicsComponent* gfxComponent : sceneEntitiesGraphics)
	{
		gfxComponent->setRenderFlag(false);
	}
}

void PlayScene::onDestroy() 
{
	// delete all items in scene
}

//void PlayScene::setSceneSwitch(unsigned int id)
//{
//	switchToState = id
//}