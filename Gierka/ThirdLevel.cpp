#include "ThirdLevel.h"

// statics
ThirdLevel ThirdLevel::l{ &Assets::thirdLevel, 8 };

// Constructors and destructor
ThirdLevel::ThirdLevel(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool ThirdLevel::isSolid() {
	return true;
}