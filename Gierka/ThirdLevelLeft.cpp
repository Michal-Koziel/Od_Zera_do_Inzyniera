#include "ThirdLevelLeft.h"

// statics
ThirdLevelLeft ThirdLevelLeft::l{ &Assets::thirdLevelLeft, 7 };

// Constructors and destructor
ThirdLevelLeft::ThirdLevelLeft(sf::Sprite* texture, int id) {
	this->texture = texture;
	this->id = id;
	texture->setScale(Tile::TILEWIDTH / 64.f, Tile::TILEHEIGHT / 64.f);
	Tile::tiles[id] = this;
}

// Functions
bool ThirdLevelLeft::isSolid() {
	return true;
}