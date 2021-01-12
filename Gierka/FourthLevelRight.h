#ifndef FourthLevelRight_hpp
#define FourthLevelRight_hpp
#include "Assets.h"
#include "Tile.h"

class FourthLevelRight :
	public Tile
{
private:
	static FourthLevelRight l;

public:
	FourthLevelRight(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif