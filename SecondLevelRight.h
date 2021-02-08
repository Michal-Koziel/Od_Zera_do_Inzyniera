#ifndef SecondLevelRight_hpp
#define SecondLevelRight_hpp
#include "Assets.h"
#include "Tile.h"

class SecondLevelRight :
	public Tile
{
private:
	static SecondLevelRight l;

public:
	SecondLevelRight(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif