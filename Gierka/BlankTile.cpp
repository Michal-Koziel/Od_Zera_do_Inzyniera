#include "BlankTile.h"

// statics
BlankTile BlankTile::l{ 0 };

// Constructors and destructor
BlankTile::BlankTile(int id) {
	this->texture = &Assets::blankTile; // zmieniæ grafikê
	this->id = id;
	Tile::tiles[id] = this;
}


