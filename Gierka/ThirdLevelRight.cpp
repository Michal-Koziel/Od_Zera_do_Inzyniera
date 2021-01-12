#include "ThirdLevelRight.h"

// statics
ThirdLevelRight ThirdLevelRight::l{ &Assets::thirdLevelRight, 9 };

// Constructors and destructor
ThirdLevelRight::ThirdLevelRight(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool ThirdLevelRight::isSolid() {
	return true;
}