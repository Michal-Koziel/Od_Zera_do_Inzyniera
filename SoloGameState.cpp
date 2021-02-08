#include "SoloGameState.h"

// Constructors and destructor

SoloGameState::SoloGameState() {
	Window = nullptr;
}

// Initializing

void SoloGameState::Init(sf::RenderWindow* Window, int width, int height) {
	this->Window = Window;
	gameCamera.Init((float)width, (float)height);
	world.init(Window, this->table, "Resources/Worlds/world.txt",&gameCamera,false);
}

// Functions

void SoloGameState::update() {
	world.update(&gameCamera);
}

void SoloGameState::render() {
	world.render(&gameCamera);
}
