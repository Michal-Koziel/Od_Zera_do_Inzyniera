#include "FourthLevelRight.h"

// statics
FourthLevelRight FourthLevelRight::l{ &Assets::fourthLevelRight, 12 };

// Constructors and destructor
FourthLevelRight::FourthLevelRight(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool FourthLevelRight::isSolid() {
	return true;
}