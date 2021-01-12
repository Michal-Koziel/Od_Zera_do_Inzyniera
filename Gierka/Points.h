#ifndef Points_hpp
#define Points_hpp

#include "Entity.h"
#include "GameCamera.h"
#include "Assets.h"

class Points :
	public Entity
{
private:
	sf::RectangleShape point;
	sf::Texture* pointTexture;
	bool activity;
public:
	Points(float x, float y);
	void render(sf::RenderWindow* window, GameCamera* gameCamera);
	void setTexture(sf::Texture* text);
	bool isPoints();
	bool isActive();
	void setActivity(bool a);
	void setPosition(float x, float y);
};

#endif
