#include "Entity.h"

// Constructors and destructor

Entity::Entity(){
	this->x = 0;
	this->y = 0;
	this->width = 64;
	this->height = 64;
	bounds.setSize(sf::Vector2f(width, height));
	bounds.setPosition(5, 5);
}

// Functions

sf::RectangleShape Entity::getCollisionBounds(float xOffset, float yOffset) {
	sf::RectangleShape bounds2;
	bounds2.setSize(sf::Vector2f(width, height));
	bounds2.setPosition(x + xOffset + bounds.getPosition().x, y + yOffset + bounds.getPosition().y);
	return bounds2;
}

// Virtual Functions

void Entity::update() {

}

void Entity::render() {

}

// Getters and setters
float Entity::getX() {
	return x;
}

float Entity::getY() {
	return y;
}

float Entity::getWidth() {
	return width;
}

float Entity::getHeight() {
	return height;
}

bool Entity::isPoints() {
	return false;
}