#ifndef EntityManager_hpp
#define EntityManager_hpp
#include "Entity.h"
#include "Points.h"
#include "GameCamera.h"
#include <iostream>
#include <vector>

class EntityManager
{
private:
	Points* p;

public:
	EntityManager();
	void update(GameCamera* gameCamera);
	void render(sf::RenderWindow* window, GameCamera* gameCamera);
	void setPoint(Points* e);
	Points* getPoint();
};


#endif