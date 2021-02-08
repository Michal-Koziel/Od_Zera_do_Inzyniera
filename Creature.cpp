#include "Creature.h"

int Creature::DEFAULT_HEALTH = 3;
float Creature::DEFAULT_SPEED = 2.0f;
float Creature::DEFAULT_CREATURE_WIDTH = 100;
float Creature::DEFAULT_CREATURE_HEIGHT = 135;

// Constructors and destructor

Creature::Creature(){
	this->x = 0;
	this->y = 0;
	this->width = 64;
	this->height = 64;
	bounds.setSize(sf::Vector2f(width, height));
	bounds.setPosition(5, 5);
	health = DEFAULT_HEALTH;
	speed = DEFAULT_SPEED;
	xMove = 0;
	yMove = 0;
}

// Functions

bool Creature::CollisionWithTile(int x, int y, int** Worldtiles) {
	x -= 6;
	if (x <= 0 || y >=619  || x >=21  || y <= 0) {
		return true;
	}

	Tile* t = Tile::tiles[ Worldtiles[x][y] ];

	if (t == nullptr) {
		return false;
	}

	return t->isSolid();
}

void Creature::Move(int** Worldtiles) {
	MoveX(Worldtiles);
	MoveY(Worldtiles);
}

void Creature::MoveX(int** Worldtiles) {
	if (xMove > 0) {   // Moving right
		if(x+xMove<=25* Tile::TILEWIDTH)
			x += xMove;
	}

	else if (xMove < 0) {   // Moving left
	//	int tx = (int)(x + xMove + bounds.getPosition().x) / Tile::TILEWIDTH;
		//if (!CollisionWithTile(tx, (int)(y + bounds.getPosition().y) / Tile::TILEHEIGHT, Worldtiles) &&
		//	!CollisionWithTile(tx, (int)(y + bounds.getPosition().y + (bounds.getSize().y / 2.5f ) ) / Tile::TILEHEIGHT, Worldtiles) &&
		//	!CollisionWithTile(tx, (int)(y + bounds.getPosition().y + (bounds.getSize().y / 1.25f)) / Tile::TILEHEIGHT, Worldtiles) &&
		//	!CollisionWithTile(tx, (int)(y + bounds.getPosition().y + bounds.getSize().y) / Tile::TILEHEIGHT, Worldtiles)) {
		if (x + xMove >= 7 * Tile::TILEWIDTH)
			x += xMove;
	}
}

void Creature::MoveY(int** Worldtiles) {
	if (yMove > 0) {   // Moving down
		int ty = (int)(y + yMove + bounds.getPosition().y + bounds.getSize().y) / Tile::TILEHEIGHT;
		if (!CollisionWithTile((int)(x + bounds.getPosition().x) / Tile::TILEWIDTH, ty, Worldtiles) &&
			!CollisionWithTile((int)(x + bounds.getPosition().x + (bounds.getSize().x / 2)) / Tile::TILEWIDTH, ty, Worldtiles) &&
			!CollisionWithTile((int)(x + bounds.getPosition().x + bounds.getSize().x) / Tile::TILEWIDTH, ty, Worldtiles)) {
				y += yMove; 
		}
		else {
			y = ty * Tile::TILEHEIGHT - bounds.getPosition().y - bounds.getSize().y - 1;
		}

	}
	else if (yMove < 0) {   // Moving up
				y += yMove; 
	}
}

bool Creature::isStanding(int** Worldtiles) {
	int ty = (int)(y + yMove + bounds.getPosition().y + bounds.getSize().y) / Tile::TILEHEIGHT;

	if (!CollisionWithTile((int)(x + bounds.getPosition().x) / Tile::TILEWIDTH, ty, Worldtiles) &&
		!CollisionWithTile((int)(x + bounds.getPosition().x + (bounds.getSize().x / 2)) / Tile::TILEWIDTH, ty, Worldtiles) &&
		!CollisionWithTile((int)(x + bounds.getPosition().x + bounds.getSize().x) / Tile::TILEWIDTH, ty, Worldtiles)) {
		return false;
	}
	return true;
}

// Getters and setters

float Creature::getSpeed(){
	return speed;
}

void Creature::setXMove(float x) {
	xMove = x;
}

void Creature::setYMove(float y) {
	yMove = y;
}

float Creature::getXMove() {
	return xMove;
}

float Creature::getYMove() {
	return yMove;
}