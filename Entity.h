#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	float x, y;
	float width, height;
	sf::RectangleShape bounds;   // collision rectangle

public:
	Entity();
	sf::RectangleShape getCollisionBounds(float xOffset, float yOffset);
	virtual void update();
	virtual void render();
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	bool isPoints();
};

#endif