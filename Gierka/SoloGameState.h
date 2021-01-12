#ifndef SoloGameState_hpp
#define SoloGameState_hpp

#include <SFML/Graphics.hpp>
#include "State.h"
#include "World.h"
#include "GameCamera.h"

class SoloGameState :
	public State
{
private:
	sf::RenderWindow* Window;
	GameCamera gameCamera{ 0,0 };
	World world;

public:
	SoloGameState();
	void Init(sf::RenderWindow* Window, int width, int height);
	void update();
	void render();
};


#endif