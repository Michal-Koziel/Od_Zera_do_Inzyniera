#include "ThirdLevelLeft.h"

// statics
ThirdLevelLeft ThirdLevelLeft::l{ &Assets::thirdLevelLeft, 7 };

// Constructors and destructor
ThirdLevelLeft::ThirdLevelLeft(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	Tile::tiles[id] = this;
}

// Functions
bool ThirdLevelLeft::isSolid() {
	return true;
}