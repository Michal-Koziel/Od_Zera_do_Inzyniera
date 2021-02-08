#include "FourthLevel.h"

// statics
FourthLevel FourthLevel::l{ &Assets::fourthLevel, 11 };

// Constructors and destructor
FourthLevel::FourthLevel(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	Tile::tiles[id] = this;
}

// Functions
bool FourthLevel::isSolid() {
	return true;
}