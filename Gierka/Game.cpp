#include "Game.h"

// Constructor and destructor

Game::Game(std::string title, int width, int height){
	this->width = width;
	this->height = height;
	this->title = title;
	init();
};

Game::~Game() {
	this->Window->close();
};


// Initializing

void Game::init() {

	// Window init
	this->Window = nullptr;
	this->Window = new sf::RenderWindow(sf::VideoMode( width ,height, 32), title);  //, sf::Style::Fullscreen);
	this->Window->setActive(true);
	this->Window->setKeyRepeatEnabled(false);
	this->Window->setFramerateLimit(180);

	// Assets init
	Assets::Init();

	// States and States table initialazing

	table[0] = &menuState;
	table[1] = &soloGameState;
	table[2] = &multiplayerState;
	table[3] = &ipState;

	menuState.InitTable(table);
	soloGameState.InitTable(table);
	multiplayerState.InitTable(table);
	ipState.InitTable(table);

	menuState.Init(Window);
	soloGameState.Init(Window,width,height);
	multiplayerState.Init(Window,width, height);
	ipState.Init(Window);

	// Choosing menustate to as actual state
	State::setState(table[0]);
}

// Accessors

bool Game::isRunning() {
	return this->Window->isOpen();
}

// Functions

void Game::run() {
	// Main game loop

	while (isRunning()) {
		update();
		render();
	}

}

void Game::update() {
	State::getState()->update();
}

void Game::render() {
	State::getState()->render();
}
