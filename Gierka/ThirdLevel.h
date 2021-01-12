#ifndef ThirdLevel_hpp
#define ThirdLevel_hpp
#include "Assets.h"
#include "Tile.h"

class ThirdLevel :
	public Tile
{
private:
	static ThirdLevel l;

public:
	ThirdLevel(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif