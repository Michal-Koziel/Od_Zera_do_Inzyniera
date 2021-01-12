#include "MultiplayerState.h"

// Constructors and destructor

MultiplayerState::MultiplayerState() {
	Window = nullptr;
}

// Initializing

void MultiplayerState ::Init(sf::RenderWindow* Window, int width, int height) {
	this->Window = Window;
	gameCamera.Init((float)width, (float)height);
	world.init(Window, this->table, "Resources/Worlds/world.txt", &gameCamera, true);
	world.setIsReady(false);
}

// Functions

void MultiplayerState::update() {
	if (world.getIsReady())
		world.update(&gameCamera);
	else {
		world.setIsReady( world.initNetwork());
	}
}

void MultiplayerState::render() {
	if (world.getIsReady())
		world.render(&gameCamera);
}
