#ifndef ThirdLevelLeft_hpp
#define ThirdLevelLeft_hpp
#include "Assets.h"
#include "Tile.h"

class ThirdLevelLeft :
	public Tile
{
private:
	static ThirdLevelLeft l;

public:
	ThirdLevelLeft(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif