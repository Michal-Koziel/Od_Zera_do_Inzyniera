#include "SecondLevel.h"

// statics
SecondLevel SecondLevel::l{ &Assets::secondLevel, 5 };

// Constructors and destructor
SecondLevel::SecondLevel(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool SecondLevel::isSolid() {
	return true;
}