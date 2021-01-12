#ifndef Mouse_hpp
#define Mouse_hpp
#include <SFML/Graphics.hpp>

class Mouse
{
private:
	sf::RenderWindow* window;

public:
	void Init(sf::RenderWindow* window, int mouse_width, int mouse_height);
	sf::Vector2i getPosition(sf::RenderWindow* window);
	sf::FloatRect mouse_box;
};

#endif
