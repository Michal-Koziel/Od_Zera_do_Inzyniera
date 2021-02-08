#ifndef Player_hpp
#define Player_hpp
#include "Creature.h"
#include "Animation.h"
#include "GameCamera.h"

class Player :
	public Creature
{
private:
	Animation AnimDown, AnimUp, AnimLeft, AnimRight, AnimStand, AnimJumpLeft, AnimJumpRight, AnimFallLeft, AnimFallRight;
	sf::RectangleShape playerObject;

public:
	Player(float x, float y);
	void update(int** Worldtiles);
	void render(sf::RenderWindow* window, GameCamera* gameCamera);
	void checkEntityCollision();
	void setTexture(sf::Texture* texture);
	sf::Texture* getTexture(int** Worldtiles);
	void setPosition(float x, float y);
	void changeColor();
};

#endif