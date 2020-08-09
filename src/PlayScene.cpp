#include "PlayScene.h"
#include "game.h"

PlayScene::PlayScene() : deck(0), map(0) {}

void PlayScene::onCreate()
{
	map = new Map(1280, 720);
	deck = new Deck(Game::entityManager);
}

void PlayScene::onActivate() 
{
	// add things to render/update pipeline
}	

void PlayScene::onDeactivate()
{
	// remove things from render/update pipeline
}

void PlayScene::onDestroy() 
{
	// delete all items in scene	
}

//void PlayScene::setSceneSwitch(unsigned int id)
//{
//	switchToState = id
//}