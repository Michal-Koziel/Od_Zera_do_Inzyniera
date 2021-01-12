#ifndef Tile_hpp
#define Tile_hpp

#include <string>
#include <SFML/Graphics.hpp>

class Tile
{
protected:
	sf::Sprite* texture;
	int id;

public:
	// Static table of tiles
	static Tile* tiles[];
	static int TILEWIDTH, TILEHEIGHT;

	// Non static functions and variables
	Tile();
	void update();
	virtual void render(sf::RenderWindow* window, float x, float y);
	virtual bool isSolid();
	int getId();
};

#endif