#ifndef MenuState_hpp
#define MenuState_hpp

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Mouse.h"
#include "Button.h"
#include "Assets.h"
#include "Animation.h"
#include "Utils.h"


class MenuState :
	public State
{
private:
	sf::RenderWindow* Window;
	sf::Event event;
	// Animation
	sf::Sprite face;
	Animation faceAnim;
	int operatingMode;
	std::string scores[11];
	sf::Text text;
	sf::Font font;

	// Buttons
	Mouse mouse;
	Button start { 660,100,890,290 };
	Button multiplayer { 660,100,890,390 };
	Button instruction{ 660,100,890,490 };
	Button score { 660,100,890,590 };
	Button exit { 660,100,890,780 };
	Button door{ 60,90,1470,796 };

	void pollEvents();

public:
	MenuState();
	void update();
	void render();
	void Init(sf::RenderWindow* Window);

};


#endif