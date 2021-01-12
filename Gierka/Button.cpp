#include "Button.h"

// Constructors and destructor

Button::Button(int width, int height,int xPos,int yPos) {
	sf::Vector2f V;
	V.x = (float)width;
	V.y = (float)height;
	button.setSize(V);
	button2.setSize(V);
	button.setPosition((float)xPos, (float)yPos);
	button2.setPosition((float)xPos, (float)yPos);
}

// Initializing

void Button::setGraphics(sf::Texture* t) {
	graphics = t;
	button.setTexture(graphics);
	button2.setTexture(graphics+1);
}

// Accessibles

sf::RectangleShape Button::getButton(Mouse mouse, sf::RenderWindow* window) {
	
	mouse.mouse_box.left = mouse.getPosition(window).x;
	mouse.mouse_box.top = mouse.getPosition(window).y;

	if( button.getGlobalBounds().intersects(mouse.mouse_box) )
		return button2;
	else
		return button;
}

bool Button::ifPointed(Mouse mouse, sf::RenderWindow* window) {

	mouse.mouse_box.left = mouse.getPosition(window).x;
	mouse.mouse_box.top = mouse.getPosition(window).y;

	if (button.getGlobalBounds().intersects(mouse.mouse_box))
		return true;
	else
		return false;
}

