#ifndef World_hpp
#define World_hpp

#include <string>
#include <iostream>
#include <sstream>
#include <SFML/Network.hpp>
#include "State.h"
#include "Assets.h"
#include "Player.h"
#include "EntityManager.h"
#include "Button.h"
#include "IpState.h"

class World
{
private:
	sf::RenderWindow* Window;
	State* table[5];
	sf::Event Event;
	sf::Font font;
	sf::Text text;
	std::string numberOfPoints;
	int width, height;
	float SpawnX, SpawnY;
	int** Worldtiles;
	bool isJumping;
	float CameraSpeed;
	int score,score2;
	void loadWorld(std::string path);
	void checkEntityCollision();
	void pollEvents(GameCamera* gameCamera);

	// Entities
	Player player{0,0};
	Points point{ (float)(24*Tile::TILEWIDTH),(float)(607*Tile::TILEWIDTH) };
	EntityManager entMan;

	// Multiplayer
	bool isMultiplayer;
	Player player2{ 0,0 };
	sf::UdpSocket socket;   
	sf::SocketSelector selector;
	sf::IpAddress ip;
	sf::IpAddress ip2;
	unsigned short port;
	unsigned short port2;
	sf::Packet packet;
	sf::Vector2f prevPositon, prevPositon2, p2Position;
	int score3, score4, score5;
	char connectionType;	
	bool isReady;

	// End game variables and fuctions
	int renderNumber;
	int counter;
	bool isWon = false;
	Button door{60,90,1095,725};
	Mouse mouse;
	void lostGame(GameCamera* gameCamera);
	void wonGame(GameCamera* gameCamera);
	void resetWorld(GameCamera* gameCamera);
	void saveScore(int score);

public:
	World();
	void init(sf::RenderWindow* window, State* tab[5], std::string path, GameCamera* gameCamera, bool multiplayer);
	bool initNetwork();
	void update(GameCamera* gameCamera);
	void render(GameCamera* gameCamera);

	Tile getTile(int x, int y);
	Player getPlayer();
	bool getIsReady();
	void setIsReady(bool isready);
	

};
#endif
