#ifndef IpState_hpp
#define IpState_hpp

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Assets.h"
#include "Button.h"


class IpState :
	public State
{
private:
	sf::RenderWindow* Window;
	sf::Event event;
	void pollEvents();
	std::string string;
	sf::Text text;
	sf::Text text2;
	sf::Font font;
	Button deleteButton{ 330,100,900,400 };
	Button connectButton{ 330,100,400,700 };
	Button returnButton{ 60,90,1175,700 };
	Mouse mouse;

public:
	IpState();
	void update();
	void render();
	void Init(sf::RenderWindow* Window);
	static std::string ipAdress;

};

#endif