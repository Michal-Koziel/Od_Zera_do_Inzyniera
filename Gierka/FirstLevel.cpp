#include "FirstLevel.h"

// statics
FirstLevel FirstLevel::l{ &Assets::firstLevel, 2 };

// Constructors and destructor
FirstLevel::FirstLevel(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH/64.f,Tile::TILEHEIGHT/64.f);
	Tile::tiles[id] = this;
}

// Functions
bool FirstLevel::isSolid() {
	return true;
}