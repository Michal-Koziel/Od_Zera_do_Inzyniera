#ifndef BlankTile_hpp
#define BlankTile_hpp
#include "Tile.h"
#include "Assets.h"

class BlankTile :
	public Tile
{
private:
	static BlankTile l;

public:
	BlankTile( int id);
};

#endif