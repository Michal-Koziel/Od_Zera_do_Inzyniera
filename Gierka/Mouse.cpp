#include "Mouse.h"

// Initialization

void Mouse::Init(sf::RenderWindow* window, int mouse_width, int mouse_height)
{
	this->window = window;

	//initialize box
	mouse_box.width = mouse_width;
	mouse_box.height = mouse_height;
}


// Accessibles

sf::Vector2i Mouse::getPosition(sf::RenderWindow* window) {
	return sf::Mouse::getPosition(*window);
}