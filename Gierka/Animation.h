#ifndef Animation_hpp
#define Animation_hpp
#include <SFML/Graphics.hpp>
#include "Assets.h"

class Animation
{
private:
	int index;
	int numberOfElements;
	sf::Texture* frames;
	sf::Time speed;
	sf::Clock clock;


public:
	void Init(int speed, int NumberOfElements, sf::Texture* table);
	void update();
	sf::Texture* getFrames();
	int getIndex();
};

#endif