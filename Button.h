#ifndef Button_hpp
#define Button_hpp
#include <SFML/Graphics.hpp>
#include "Mouse.h"

class Button
{
private:
	sf::RectangleShape button,button2;
	sf::Texture* graphics;
public:
	Button(int width,int height, int xPos, int yPos);
	void setGraphics(sf::Texture* t);
	sf::RectangleShape getButton(Mouse mouse, sf::RenderWindow* window);
	bool ifPointed(Mouse mouse, sf::RenderWindow* window);
};

#endif

