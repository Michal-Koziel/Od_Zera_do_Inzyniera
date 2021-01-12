#include "FourthLevelLeft.h"

// statics
FourthLevelLeft FourthLevelLeft::l{ &Assets::fourthLevelLeft, 10 };

// Constructors and destructor
FourthLevelLeft::FourthLevelLeft(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool FourthLevelLeft::isSolid() {
	return true;
}