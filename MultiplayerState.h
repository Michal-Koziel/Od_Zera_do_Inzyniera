#ifndef MultiplayerState_hpp
#define MultiplayerState_hpp

#include "State.h"
#include "World.h"

class MultiplayerState :
	public State
{
private:
	sf::RenderWindow* Window;
	GameCamera gameCamera{ 0,0 };
	World world;


public:
	MultiplayerState();
	void Init(sf::RenderWindow* Window, int width, int height);
	void update();
	void render();
};


#endif