#include "SecondLevelLeft.h"

// statics
SecondLevelLeft SecondLevelLeft::l{ &Assets::secondLevelLeft, 4 };

// Constructors and destructor
SecondLevelLeft::SecondLevelLeft(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool SecondLevelLeft::isSolid() {
	return true;
}