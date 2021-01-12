#include "FirstLevelLeft.h"

// statics
FirstLevelLeft FirstLevelLeft::l{ &Assets::firstLevelLeft, 1 };

// Constructors and destructor
FirstLevelLeft::FirstLevelLeft(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool FirstLevelLeft::isSolid() {
	return true;
}