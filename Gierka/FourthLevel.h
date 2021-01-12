#ifndef FourthLevel_hpp
#define FourthLevel_hpp
#include "Assets.h"
#include "Tile.h"

class FourthLevel :
	public Tile
{
private:
	static FourthLevel l;

public:
	FourthLevel(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif