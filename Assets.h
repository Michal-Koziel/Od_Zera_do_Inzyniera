#ifndef Assets_hpp
#define Assets_hpp
#include <SFML/Graphics.hpp>

class Assets
{
private:
	static sf::Texture menuTexture, menuTexture2, leftWallTexture, rightWallTexture, midWallTexture, backgroundTexture;
	static sf::Texture blankTexture, firstLevelTexture, firstLevelTextureLeft, firstLevelTextureRight;
	static sf::Texture secondLevelTexture, secondLevelTextureLeft, secondLevelTextureRight;
	static sf::Texture thirdLevelTexture, thirdLevelTextureLeft, thirdLevelTextureRight;
	static sf::Texture fourthLevelTexture, fourthLevelTextureLeft, fourthLevelTextureRight;
	static sf::Texture diplomaTexture, hatTexture, instructionTexture, titleTexture;

public:
	static void Init();
	static sf::Sprite menu, menu2, leftWall, rightWall, midWall, background;
	static sf::Sprite blankTile, firstLevel, firstLevelLeft, firstLevelRightt, secondLevel, secondLevelLeft, secondLevelRight;
	static sf::Sprite thirdLevel, thirdLevelLeft, thirdLevelRight, fourthLevel, fourthLevelLeft, fourthLevelRight;
	static sf::Sprite firstLevelRight, diploma, hat, instruction, title;
	static sf::Texture text1[], text2[], text3[], text4[], text5[], text6[], door[];
	static sf::Texture Face[]; 	static sf::Texture PlayerStand[]; static sf::Texture PlayerLeft[]; static sf::Texture PlayerRight[];
	static sf::Texture PlayerJump[]; static sf::Texture PlayerFall[]; static sf::Texture PlayerJumpLeft[]; static sf::Texture PlayerJumpRight[];
	static sf::Texture PlayerFallLeft[]; static sf::Texture PlayerFallRight[]; static sf::Texture point, connect[], clear[];
};

#endif