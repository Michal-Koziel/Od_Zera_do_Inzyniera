#include "Game.h"

int main()
{
	// Starting game loop on another thread
	Game game("PWR Tower", 1600, 960);
	game.run();


	return 0;
}