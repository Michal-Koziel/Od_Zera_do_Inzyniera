#ifndef FirstLevelRight_hpp
#define FirstLevelRight_hpp
#include "Assets.h"
#include "Tile.h"

class FirstLevelRight :
	public Tile
{
private:
	static FirstLevelRight l;

public:
	FirstLevelRight(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif