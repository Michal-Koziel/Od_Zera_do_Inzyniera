#ifndef Creature_hpp
#define Creature_hpp
#include "Entity.h"
#include "Tile.h"

class Creature :
	public Entity
{
protected:
	int health;
	float speed;
	float xMove, yMove;
	bool CollisionWithTile(int x, int y, int** Worldtiles);


public:
	static int DEFAULT_HEALTH;
	static float DEFAULT_SPEED;
	static float DEFAULT_CREATURE_WIDTH, DEFAULT_CREATURE_HEIGHT;

	Creature();
	void Move(int** Worldtiles);
	void MoveX(int** Worldtiles);
	void MoveY(int** Worldtiles);
	bool isStanding(int** Worldtiles);
	void setXMove(float x);
	void setYMove(float y);
	float getXMove();
	float getYMove();
	float getSpeed();


};

#endif