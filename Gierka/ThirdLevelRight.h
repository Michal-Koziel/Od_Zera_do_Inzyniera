#ifndef ThirdLevelRight_hpp
#define ThirdLevelRight_hpp
#include "Assets.h"
#include "Tile.h"

class ThirdLevelRight :
	public Tile
{
private:
	static ThirdLevelRight l;

public:
	ThirdLevelRight(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif