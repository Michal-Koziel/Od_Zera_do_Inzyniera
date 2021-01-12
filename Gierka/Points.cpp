#include "Points.h"

// Constructors and destructor

Points::Points(float x, float y) {
	this->x = x;
	this->y = y;
	this->width = 125;
	this->height = 50;
	bounds.setSize(sf::Vector2f(width-10, height-5));
	bounds.setPosition(10, 5);
	sf::Vector2f V;
	V.x = width;
	V.y = height;
	point.setSize(V);
	point.setPosition(x, y);
	activity = true;
}

// Functions

void Points::render(sf::RenderWindow* window, GameCamera* gameCamera) {
	point.setPosition(x, y - gameCamera->getyOffset());
	window->draw(point);
}

void Points::setTexture(sf::Texture* text){
	pointTexture = text;
	point.setTexture(pointTexture);
}

bool Points::isPoints() {
	return true;
}

bool Points::isActive(){
	return activity;
}

void Points::setActivity(bool a) {
	activity = a;
}

void Points::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
	point.setPosition(x, y);
}