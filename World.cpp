#include "World.h"
#include "Utils.h"

// Constructors and destructor

World::World() {
}

// Initializing

void World::init(sf::RenderWindow* window, State* tab[5],std::string path, GameCamera* gameCamera, bool multiplayer) {
	this->Window = window;
	for (int i=0;i < 5;i++)
		table[i] = tab[i];
	this->loadWorld(path);
	renderNumber = 0;
	counter = 0;
	isJumping = false;

	// Network
	isMultiplayer = multiplayer;
	if (isMultiplayer) {
		port = 2000;
		socket.bind(port);
		selector.add(socket);
		socket.setBlocking(false);
	}


	//button init
	mouse.Init(this->Window, 10, 10);
	door.setGraphics(Assets::door);
	
	// scoring
	score = 0;
	score2 = 0;
	font.loadFromFile("Resources/Fonts/Zeyada.ttf");
	numberOfPoints = "Ects : ";
	numberOfPoints += std::to_string(score);
	text.setFont(font);
	text.setCharacterSize(70);
	text.setFillColor(sf::Color(255, 255, 255));
	text.setOutlineThickness(4.f);
	text.setOutlineColor(sf::Color(0, 0, 0));
	text.setPosition(40, 880);
	text.setString(numberOfPoints);

	// entities
	player.setPosition(SpawnX, SpawnY);
	player.setYMove(player.getSpeed());
	if (isMultiplayer) {
		player2.setPosition(SpawnX, SpawnY - 30);
		player2.setYMove(player.getSpeed());
		player2.changeColor();
		score3 = 0;
	}
	point.setTexture(&Assets::point);
	entMan.setPoint(&point);

	// game camera
	CameraSpeed = 0;
	gameCamera->CenterOnEntity(player);
	gameCamera->setyOffset(gameCamera->getyOffset() - 9*Tile::TILEHEIGHT - 39);
}

bool World::initNetwork() {

	ip = sf::IpAddress(IpState::ipAdress);
	
		packet << 0 << 0;
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		if (selector.wait(sf::seconds(30.f)))
		{
			socket.receive(packet, ip2, port2);
		}
		else
		{
			State::setState(table[3]);
			return false;
		}	
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		socket.send(packet, ip, port);
		packet.clear();

	return true;
}

// Functions

void World::update(GameCamera* gameCamera) {
	if (renderNumber == 0) {

		if (isMultiplayer) {
			prevPositon2 = sf::Vector2f(player.getXMove(), player.getYMove());
			prevPositon = sf::Vector2f(player.getX(), player.getY());
		}
		pollEvents(gameCamera);
		// player move while jumping
		if (isJumping) {
			player.setYMove(player.getYMove() + 0.08f);

			if (player.getYMove() >= 4) {
				isJumping = false;
			}
		}

		player.update(Worldtiles);
		entMan.update(gameCamera);
		checkEntityCollision();
		player.setTexture(player.getTexture(Worldtiles));

		if (isMultiplayer) {
			if (prevPositon2 != sf::Vector2f(player.getXMove(), player.getYMove())) {
				packet << player.getXMove() << player.getYMove();
				socket.send(packet, ip, port);
				packet.clear();
			}

			socket.receive(packet, ip2, port2);
			if (packet >> p2Position.x >> p2Position.y) {
				if (p2Position.x > 2.0f && p2Position.y > 6.0f) {
					player2.setPosition(p2Position.x, p2Position.y);
				}
				else if( p2Position.x <= 2.f && p2Position.x >= -2.f  && p2Position.y <= 6.f && p2Position.y >= -6.f ){
					player2.setXMove(p2Position.x);
					player2.setYMove(p2Position.y);
				}
				packet.clear();
			}

			if (prevPositon != sf::Vector2f(player.getX(), player.getY()))
			{	
				packet << player.getX() << player.getY();
				socket.send(packet, ip, port);
				packet.clear();
			}

			socket.receive(packet, ip2, port2);
			if (packet >> p2Position.x >> p2Position.y) {
				if (p2Position.x > 2.0f && p2Position.y > 6.0f) {
					player2.setPosition(p2Position.x, p2Position.y);
				}
				else if (p2Position.x <= 2.f && p2Position.x >= -2.f  && p2Position.y <= 6.f && p2Position.y >= -6.f) {
					player2.setXMove(p2Position.x);
					player2.setYMove(p2Position.y);
				}
				packet.clear();
			}


			player2.update(Worldtiles);
			player2.setTexture(player2.getTexture(Worldtiles));
		}

		// changing camera speed when climbing higher
		if (player.getY() < 615 * Tile::TILEHEIGHT) {

			if (player.getY() < 165 * Tile::TILEHEIGHT)
				CameraSpeed = 0.8f;
			else if (player.getY() < 315 * Tile::TILEHEIGHT)
				CameraSpeed = 0.7f;
			else if (player.getY() < 465 * Tile::TILEHEIGHT)
				CameraSpeed = 0.6f;
			else
				CameraSpeed = 0.4f;

		}

		// centering camera on player and adding camera speed
		gameCamera->CenterOnEntity(player);
		gameCamera->setyOffset(gameCamera->getyOffset() - CameraSpeed);

		// Scoring update
		numberOfPoints = "Ects : ";
		if (score2 < (int)((29500 - player.getY()) / 100))
			score2 = (int)((29500 - player.getY()) / 100);
		numberOfPoints += std::to_string(score + score2);
		text.setString(numberOfPoints);

		// Checking if player won or lost the game
		if (gameCamera->getyOffset() <= 0 && player.getY() <= 738) {
			wonGame(gameCamera);
		}
		if (player.getY() - 980 > gameCamera->getyOffset()) {
			lostGame(gameCamera);
		}
	}
	else if (renderNumber == 1) {
		counter++;
		if (isMultiplayer){
			score4 = 0;
			score5 = 0;

			packet << -100 <<(score + score2);
			socket.send(packet, ip, port);
			packet.clear();

			socket.receive(packet, ip2, port2);
			if (packet >> score4 >> score5) {
				if (score4 == -100) {
					score3 = (score5);
				}
			}
			packet.clear();

		}
		pollEvents(gameCamera);
	}
}

void World::render(GameCamera* gameCamera) {
	if (renderNumber == 0) {
		this->Window->clear(sf::Color::White);

		// Background
		if (gameCamera->getyOffset() > 340 * Tile::TILEHEIGHT) {
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y - 0.3f*gameCamera->getyOffset());
			this->Window->draw(Assets::background);
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y + 0.3f*gameCamera->getyOffset());
		}
		if (gameCamera->getyOffset() < 420 * Tile::TILEHEIGHT) {
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y - 0.3f*gameCamera->getyOffset() - 3650);
			this->Window->draw(Assets::background);
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y + 0.3f*gameCamera->getyOffset() + 3650);
		}
		if (gameCamera->getyOffset() < 165 * Tile::TILEHEIGHT) {
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y - 0.3f*gameCamera->getyOffset() - 7300);
			this->Window->draw(Assets::background);
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y + 0.3f*gameCamera->getyOffset() + 7300);
		}

		// Tiles 
		int xStart = 0;
		int xEnd = width;
		int yStart = std::max(0, (int)(gameCamera->getyOffset() / Tile::TILEHEIGHT));
		int yEnd = std::min(height, (int)(gameCamera->getyOffset() / Tile::TILEHEIGHT + 23));

		for (int y = yStart;y < yEnd;y++) {
			for (int x = xStart;x < xEnd;x++) {
				if (Worldtiles[x][y] != 0) {
					this->getTile(x, y).render(Window,
						(float)((x + 6) * Tile::TILEWIDTH),
						(float)(y * Tile::TILEHEIGHT) - gameCamera->getyOffset());
				}
			}
		}

		// Walls
		this->Window->draw(Assets::leftWall);
		this->Window->draw(Assets::rightWall);
		Assets::midWall.setPosition(0, -64);
		this->Window->draw(Assets::midWall);
		Assets::midWall.setPosition(1432, 0);
		this->Window->draw(Assets::midWall);
		this->Window->draw(text);

		// Entities
		entMan.render(Window, gameCamera);
		if (isMultiplayer)
			player2.render(Window, gameCamera);
		player.render(Window, gameCamera);

		this->Window->display();
	}
	else if (renderNumber == 1) {
		this->Window->clear(sf::Color::White);

		// Background
		if (gameCamera->getyOffset() > 340 * Tile::TILEHEIGHT) {
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y - 0.3f*gameCamera->getyOffset());
			this->Window->draw(Assets::background);
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y + 0.3f*gameCamera->getyOffset());
		}
		if (gameCamera->getyOffset() < 420 * Tile::TILEHEIGHT) {
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y - 0.3f*gameCamera->getyOffset() - 3650);
			this->Window->draw(Assets::background);
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y + 0.3f*gameCamera->getyOffset() + 3650);
		}
		if (gameCamera->getyOffset() < 165 * Tile::TILEHEIGHT) {
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y - 0.3f*gameCamera->getyOffset() - 7300);
			this->Window->draw(Assets::background);
			Assets::background.setPosition(Assets::background.getPosition().x, Assets::background.getPosition().y + 0.3f*gameCamera->getyOffset() + 7300);
		}

		// Tiles 
		int xStart = 0;
		int xEnd = width;
		std::max(0.0f, gameCamera->getyOffset() / Tile::TILEHEIGHT);
		int yStart = std::max(0, (int)(gameCamera->getyOffset() / Tile::TILEHEIGHT));
		int yEnd = std::min(height, (int)(gameCamera->getyOffset() / Tile::TILEHEIGHT + 21));

		for (int y = yStart;y < yEnd;y++) {
			for (int x = xStart;x < xEnd;x++) {
				if (Worldtiles[x][y] != 0) {
					this->getTile(x, y).render(Window,
						(float)((x + 6) * Tile::TILEWIDTH),
						(float)(y * Tile::TILEHEIGHT) - gameCamera->getyOffset());
				}
			}
		}

		// Walls
		this->Window->draw(Assets::leftWall);
		this->Window->draw(Assets::rightWall);
		Assets::midWall.setPosition(0, -64);
		this->Window->draw(Assets::midWall);
		Assets::midWall.setPosition(1432, 0);
		this->Window->draw(Assets::midWall);

		// Entities
		entMan.render(Window, gameCamera);
		player.render(Window, gameCamera);

		// End game credits
		if (counter >= 120) {
			this->Window->draw(Assets::menu2);
		}
		if (counter >= 240) {
			text.setFillColor(sf::Color(155, 255, 155, 230));
			if (!isWon) {
				text.setString(L"Niestety");
				text.setPosition(730, 220);
				this->Window->draw(text);
				text.setString(L"Obla³eœ kolejny egzamin... ");
				text.setPosition(550, 320);
				this->Window->draw(text);
				if (counter >= 600) {
					text.setString(L"I wracasz na dziekankê");
					text.setPosition(570, 440);
					this->Window->draw(text);
				}
				if (counter >= 840) {
					text.setString(L"Zebrane Ects : ");
					text.setPosition(655, 525);
					this->Window->draw(text);
				}

				if (isMultiplayer) {
					if (counter >= 980) {
						text.setString(L"Twoje : ");
						text.setPosition(950, 625);
						this->Window->draw(text);
						text.setString(L"Wspó³lokatora : ");
						text.setPosition(550, 625);
						this->Window->draw(text);
					}
					if (counter >= 1120) {
						if (score3 == 0) {
							text.setString("W trakcie");
							text.setPosition(600, 700);
						}
						else {
							text.setString(std::to_string(score3));
							text.setPosition(700, 700);
						}
						this->Window->draw(text);
					}
				}

				if (counter >= 1120) {
					text.setString(std::to_string(score + score2));
					text.setPosition(820, 625);
					if (isMultiplayer)
						text.setPosition(1010, 700);
					this->Window->draw(text);
				}

				if (counter >= 1160) {
					this->Window->draw(door.getButton(mouse, Window));
				}
			}
			else if (isWon) {
				text.setString(L"Gratulacje!");
				text.setPosition(705, 220);
				this->Window->draw(text);
				text.setString(L"  Ukoñczy³eœ Studia i ...");
				text.setPosition(550, 320);
				this->Window->draw(text);
				if (counter >= 600) {
					text.setString(L"Zosta³eœ in¿ynierem!");
					text.setPosition(590, 440);
					this->Window->draw(text);
				}
				if (counter >= 840) {
					this->Window->draw(Assets::diploma);
					this->Window->draw(Assets::hat);
				}
				if (counter >= 840) {
					text.setString(L"Zebrane Ects : ");
					text.setPosition(655, 525);
					this->Window->draw(text);
				}

				if (isMultiplayer) {
					if (counter >= 980) {
						text.setString(L"Twoje : ");
						text.setPosition(950, 625);
						this->Window->draw(text);
						text.setString(L"Wspó³lokatora : ");
						text.setPosition(550, 625);
						this->Window->draw(text);
					}
					if (counter >= 1120) {
						if (score3 == 0) {
							text.setString("W trakcie");
							text.setPosition(600, 700);
						}
						else {
							text.setString(std::to_string(score3));
							text.setPosition(700, 700);
						}
						this->Window->draw(text);
					}
				}
				if (counter >= 1120) {
					text.setString(std::to_string(score + score2));
					text.setPosition(820, 625);
					if (isMultiplayer)
						text.setPosition(1010, 700);
					this->Window->draw(text);
				}

				if (counter >= 1160) {
					this->Window->draw(door.getButton(mouse, Window));
				}
			}
			this->Window->display();
		}
	}
}

Tile World::getTile(int x, int y) {

	if (x < 0 || y < 0 || x >= width || y >= height) {
		return *Tile::tiles[2];
	}

	if( Worldtiles[x][y] >12 || Worldtiles[x][y] < 1)
		return *Tile::tiles[0];

	Tile* t = Tile::tiles[Worldtiles[x][y]];

	return *t;
}

void World::loadWorld(std::string path) {
	std::string tokens[18000];
	Utils::loadFileAsStringArray(path,tokens);
	
	width = Utils::parseInt(tokens[0]);
	height = Utils::parseInt(tokens[1]);
	SpawnX = (float) Utils::parseInt(tokens[2])*Tile::TILEWIDTH;
	SpawnY = (float) Utils::parseInt(tokens[3])*Tile::TILEHEIGHT;
	// Creating of world table
	Worldtiles = new int*[width];
	for (int i = 0;i < width; i++) 
		Worldtiles[i] = new int[height];
	
	for (int y = 0;y < height;y++) {
		for (int x = 0;x < width;x++) {
			Worldtiles[x][y] = Utils::parseInt(tokens[(x + width * y) + 4]);
		}
	}
}

void World::checkEntityCollision() {
	if (point.getCollisionBounds(0.0f, 0.0f).getGlobalBounds().intersects(player.getCollisionBounds(0.0f, 0.0f).getGlobalBounds()) && point.isActive()){
		score += 10;
		point.setActivity(false);
	}
	// check creatures
}

void World::pollEvents(GameCamera* gameCamera) {
	if (renderNumber == 0) {
		while (this->Window->pollEvent(Event)) {
			if (Event.type == sf::Event::Closed)
				this->Window->close();

			// Horizontal movement and jumping
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::D))
				player.setXMove(player.getSpeed());
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::A))
				player.setXMove(-(player.getSpeed()));
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Space) && (player.isStanding(Worldtiles))) {
				player.setYMove(-3 * (player.getSpeed()));
				isJumping = true;
			}

			// Back to the menu
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape)) {
				if(isMultiplayer)
					resetWorld(gameCamera);
				State::setState(table[0]);
			} 


			// Stop after releasing A
			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::A))
			{
				if (player.getXMove() < 0)
					player.setXMove(0);
			}

			// Stop after releasing D
			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::D))
			{
				if (player.getXMove() > 0)
					player.setXMove(0);
			}
		}
	}
	else if (renderNumber == 1) {
		while (this->Window->pollEvent(Event)) {
			if (Event.type == sf::Event::Closed)
				this->Window->close();
			if (Event.type == sf::Event::MouseButtonPressed && (Event.mouseButton.button == sf::Mouse::Left)) {
				if (door.ifPointed(mouse, Window) && counter>= 980) {
					resetWorld(gameCamera);
					State::setState(table[0]);
				}
			}

		}
	}
}   

void World::resetWorld(GameCamera* gameCamera) {
	// score
	score = 0;
	score2 = 0;

	// entities
	player.setPosition(SpawnX, SpawnY);
	player.setYMove(player.getSpeed());
	if(isMultiplayer){
		player2.setPosition(SpawnX, SpawnY);
		player2.setYMove(player.getSpeed());
		isReady = false;
		score3 = 0;
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
		socket.receive(packet, ip2, port2);
	}
	isJumping = false;
	point.setActivity(true);
	point.setPosition((float)(24 * Tile::TILEWIDTH), (float)(607 * Tile::TILEWIDTH));

	// game camera
	CameraSpeed = 0;
	gameCamera->setyOffset((float)(599 * Tile::TILEWIDTH));

	// End game variables
	counter = 0;
	renderNumber = 0;
	text.setString(numberOfPoints);
	text.setPosition(40, 880);
	text.setFillColor(sf::Color(255, 255, 255));
	Assets::menu2.setPosition(890, 280);
}

void World::saveScore(int score) {
	std::string path = "Resources/Scores/score.txt";
	std::string scoresBefore[11];
	std::string scoresAfter;
	int yourscore = score;
	int swapHelper;
	int HighScores[10];

	Utils::loadFileAsStringArray(path, scoresBefore);

	for (int i = 0;i < 10;i++) {
		// if your score is higher then actual switch them
		HighScores[i] = Utils::parseInt(scoresBefore[i]);
		if (yourscore > HighScores[i]) {  
			swapHelper = HighScores[i];
			HighScores[i] = yourscore;
			yourscore = swapHelper;
		}
		scoresAfter += std::to_string(HighScores[i]) + " ";
	}

	Utils::saveToFile(path, scoresAfter);

}

void World::lostGame(GameCamera* gameCamera) {
	saveScore(score + score2);
	renderNumber = 1;
	counter = 0;
	Assets::menu2.setPosition(500, 200);
	isWon = false;
}

void World::wonGame(GameCamera* gameCamera) {
	saveScore(score + score2);
	renderNumber = 1;
	counter = 0;
	Assets::menu2.setPosition(500, 200);
	isWon = true;
}

Player World::getPlayer() {
	return player;
}

bool World::getIsReady() {
	return isReady;
}

void World::setIsReady(bool isready) {
	isReady = isready;
}
