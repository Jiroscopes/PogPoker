#pragma once

class Scene
{
private:

public:
	virtual void onCreate() = 0;
	virtual void onDestroy() = 0;

	virtual void onActivate() {};
	virtual void onDeactivate() {};

	//virtual void processInput() {};
	//virtual void update() {};
	//virtual void render() {};

};