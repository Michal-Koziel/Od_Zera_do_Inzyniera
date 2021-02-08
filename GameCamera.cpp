#include "GameCamera.h"

// Constructors and destructor

GameCamera::GameCamera(float xOffset, float yOffset) {
	this->xOffset = xOffset;
	this->yOffset = yOffset;

}

// Initialization

void GameCamera::Init(float width, float height) {
	this->width = width;
	this->height = height;
}

// Functions

void GameCamera::CheckBlankSpace() {
	// If camera go beyond the map on top side
	if (yOffset < 0)
		yOffset = 0;

	//if (yOffset + handler.getHeight() > handler.getWorld().getHeight()*Tiles::TILEHEIGHT)
	//	yOffset = handler.getWorld().getHeight()*Tiles::TILEHEIGHT - handler.getHeight();
}

void GameCamera::CenterOnEntity(Entity E) {
	float oldyOffset;
	oldyOffset = yOffset;
	yOffset = E.getY() - height/2 + E.getHeight();
	if (oldyOffset!=0 && oldyOffset < yOffset)
		yOffset = oldyOffset;
	CheckBlankSpace();
}

void GameCamera::Move(float x, float y) {
	xOffset += x;
	yOffset += y;
}

float GameCamera::getxOffset() {
	return xOffset;
}

float GameCamera::getyOffset() {
	return yOffset;
}

void GameCamera::setxOffset(float x) {
	xOffset = x;
}

void GameCamera::setyOffset(float y) {
	yOffset = y;
}