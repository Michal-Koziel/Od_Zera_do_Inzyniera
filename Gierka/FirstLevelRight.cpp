#include "FirstLevelRight.h"

// statics
FirstLevelRight FirstLevelRight::l{ &Assets::firstLevelRightt, 3 };

// Constructors and destructor
FirstLevelRight::FirstLevelRight(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool FirstLevelRight::isSolid() {
	return true;
}