#include "FourthLevel.h"

// statics
FourthLevel FourthLevel::l{ &Assets::fourthLevel, 11 };

// Constructors and destructor
FourthLevel::FourthLevel(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool FourthLevel::isSolid() {
	return true;
}