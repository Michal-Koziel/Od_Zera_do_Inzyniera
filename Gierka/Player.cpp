#include "Player.h"

// Constructors and destructor

Player::Player(float x, float y) {

	this->x = x;
	this->y = y;
	this->width = Creature::DEFAULT_CREATURE_WIDTH;
	this->height = Creature::DEFAULT_CREATURE_HEIGHT;

	bounds.setSize(sf::Vector2f(width-25, height-25));
	bounds.setPosition(5, 15);

	health = DEFAULT_HEALTH;
	speed = DEFAULT_SPEED;
	xMove = 0;
	yMove = 0;
	AnimDown.Init(200, 2, Assets::PlayerFall);
	AnimUp.Init(500, 1, Assets::PlayerJump);
	AnimLeft.Init(250, 4, Assets::PlayerLeft);
	AnimRight.Init(250, 4, Assets::PlayerRight);
	AnimStand.Init(350, 2, Assets::PlayerStand);
	AnimJumpLeft.Init(1000, 1, Assets::PlayerJumpLeft);
	AnimJumpRight.Init(1000, 1, Assets::PlayerJumpRight);
	AnimFallLeft.Init(200, 2, Assets::PlayerFallLeft);
	AnimFallRight.Init(200, 2, Assets::PlayerFallRight);

	playerObject.setPosition(x,y);
	playerObject.setSize(sf::Vector2f(width, height));
}

// Functions

void Player::update(int** Worldtiles) {

	AnimUp.update();
	AnimDown.update();
	AnimLeft.update();
	AnimRight.update();
	AnimStand.update();
	AnimJumpLeft.update();
	AnimJumpRight.update();
	AnimFallLeft.update();
	AnimFallRight.update();

	Move(Worldtiles);
	playerObject.setPosition(x, y);
}

void Player::render(sf::RenderWindow* window, GameCamera* gameCamera) {
	playerObject.setPosition(x, y - gameCamera->getyOffset());
	window->draw(playerObject);
	playerObject.setPosition(x, y + gameCamera->getyOffset());
}

void Player::checkEntityCollision() {



}

void Player::setTexture(sf::Texture* texture) {
	playerObject.setTexture(texture);
}

sf::Texture* Player::getTexture(int** Worldtiles) {


	if (yMove < 0) {
		if(xMove < 0)
			return &AnimJumpLeft.getFrames()[AnimJumpLeft.getIndex()];
		if (xMove > 0) 
			return &AnimJumpRight.getFrames()[AnimJumpRight.getIndex()];

		return &AnimUp.getFrames()[AnimUp.getIndex()];
	}

	int ty = (int)(y + yMove + bounds.getPosition().y + bounds.getSize().y) / Tile::TILEHEIGHT;
	if (yMove > 0 && (!CollisionWithTile((int)(x + bounds.getPosition().x) / Tile::TILEWIDTH, ty, Worldtiles) &&
		!CollisionWithTile((int)(x + bounds.getPosition().x + (bounds.getSize().x / 2)) / Tile::TILEWIDTH, ty, Worldtiles) &&
		!CollisionWithTile((int)(x + bounds.getPosition().x + bounds.getSize().x) / Tile::TILEWIDTH, ty, Worldtiles)) ) {

		if (xMove < 0)
			return &AnimFallLeft.getFrames()[AnimFallLeft.getIndex()];
		if (xMove > 0)
			return &AnimFallRight.getFrames()[AnimFallRight.getIndex()];

		return &AnimDown.getFrames()[AnimDown.getIndex()];
	}


	if (xMove < 0) {
		return &AnimLeft.getFrames()[AnimLeft.getIndex()];
	}
	if (xMove > 0) {
		return &AnimRight.getFrames()[AnimRight.getIndex()];
	}

	return &AnimStand.getFrames()[AnimStand.getIndex()];

}

void Player::changeColor() {
	//playerObject.setFillColor(sf::Color(100,255,100));
	playerObject.setFillColor(sf::Color::Cyan);
}

void Player::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
	playerObject.setPosition(x,y);
}

