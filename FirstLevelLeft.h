#ifndef FirstLevelLeft_hpp
#define FirstLevelLeft_hpp
#include "Assets.h"
#include "Tile.h"

class FirstLevelLeft :
	public Tile
{
private:
	static FirstLevelLeft l;

public:
	FirstLevelLeft(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif