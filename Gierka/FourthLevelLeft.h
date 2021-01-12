#ifndef FourthLevelLeft_hpp
#define FourthLevelLeft_hpp
#include "Assets.h"
#include "Tile.h"

class FourthLevelLeft :
	public Tile
{
private:
	static FourthLevelLeft l;

public:
	FourthLevelLeft(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif