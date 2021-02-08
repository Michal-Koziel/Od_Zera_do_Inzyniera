#include "Tile.h"


// statics
int Tile::TILEHEIGHT = 48;
int Tile::TILEWIDTH = 48;
Tile* Tile::tiles[16] = {};

// Constructors and destructor
Tile::Tile() {
}

// Functions
void Tile::render(sf::RenderWindow* window, float x, float y) {
	texture->setPosition(x, y);
	window->draw(*texture);
}

void Tile::update() {

}

bool Tile::isSolid() {
	return false;
}

int Tile::getId() {
	return id;
}