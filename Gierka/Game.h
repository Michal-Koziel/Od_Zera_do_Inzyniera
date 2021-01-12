#ifndef Game_hpp
#define Game_hpp

#include <string>
#include <SFML/Graphics.hpp>
#include "State.h"

#include "MenuState.h"
#include "SoloGameState.h"
#include "MultiplayerState.h"
#include "IpState.h"



class Game
{
private:
	int width, height;
	std::string title;
	sf::RenderWindow* Window;
	MenuState menuState;
	SoloGameState soloGameState;
	MultiplayerState multiplayerState;
	IpState ipState;
	
	void init();
	void update();
	void render();
	bool isRunning();

public:
	Game(std::string title, int width, int height);
	virtual ~Game();
	void run();
	State* table[4];

};

#endif

