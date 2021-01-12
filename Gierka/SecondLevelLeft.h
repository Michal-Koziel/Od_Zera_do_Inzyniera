#ifndef SecondLevelLeft_hpp
#define SecondLevelLeft_hpp
#include "Assets.h"
#include "Tile.h"

class SecondLevelLeft :
	public Tile
{
private:
	static SecondLevelLeft l;

public:
	SecondLevelLeft(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif