#ifndef SecondLevel_hpp
#define SecondLevel_hpp
#include "Assets.h"
#include "Tile.h"

class SecondLevel :
	public Tile
{
private:
	static SecondLevel l;

public:
	SecondLevel(sf::Sprite* texture, int id);
	bool isSolid();
};

#endif