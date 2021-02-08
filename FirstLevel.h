#ifndef FirstLevel_hpp
#define FirstLevel_hpp
#include "Assets.h"
#include "Tile.h"

class FirstLevel :
	public Tile
{
private:
	static FirstLevel l;

public:
	FirstLevel(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif