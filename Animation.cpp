#include "Animation.h"

void Animation::Init(int speed, int NumberOfElements, sf::Texture* table) {
	numberOfElements = NumberOfElements;
	this->speed = sf::milliseconds(speed);
	frames = table;
	index = 0;
}

void Animation::update() {

	if ( clock.getElapsedTime() >= speed ) {
		index++;
		if (index >= numberOfElements)
			index = 0;
		clock.restart();
	}
}

sf::Texture* Animation::getFrames() {
	return frames;
}

int Animation::getIndex() {
	return index;
}