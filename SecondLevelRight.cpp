#include "SecondLevelRight.h"

// statics
SecondLevelRight SecondLevelRight::l{ &Assets::secondLevelRight, 6 };

// Constructors and destructor
SecondLevelRight::SecondLevelRight(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	Tile::tiles[id] = this;
}

// Functions
bool SecondLevelRight::isSolid() {
	return true;
}