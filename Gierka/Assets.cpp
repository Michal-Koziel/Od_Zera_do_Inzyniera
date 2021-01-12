#include "Assets.h"

sf::Texture Assets::menuTexture; sf::Texture Assets::menuTexture2; sf::Texture Assets::blankTexture; sf::Texture Assets::point;
sf::Texture Assets::rightWallTexture; sf::Texture Assets::leftWallTexture; sf::Texture Assets::midWallTexture; sf::Texture Assets::backgroundTexture;
sf::Texture Assets::firstLevelTexture; sf::Texture Assets::firstLevelTextureLeft; sf::Texture Assets::firstLevelTextureRight;
sf::Texture Assets::secondLevelTexture; sf::Texture Assets::secondLevelTextureLeft; sf::Texture Assets::secondLevelTextureRight;
sf::Texture Assets::thirdLevelTexture; sf::Texture Assets::thirdLevelTextureLeft; sf::Texture Assets::thirdLevelTextureRight;
sf::Texture Assets::fourthLevelTexture; sf::Texture Assets::fourthLevelTextureLeft; sf::Texture Assets::fourthLevelTextureRight;
sf::Texture Assets::diplomaTexture; sf::Texture Assets::hatTexture; sf::Texture Assets::instructionTexture; sf::Texture Assets::titleTexture;

sf::Sprite Assets::menu; sf::Sprite Assets::menu2; sf::Sprite Assets::leftWall; sf::Sprite Assets::rightWall; sf::Sprite Assets::midWall;
sf::Sprite Assets::firstLevel; sf::Sprite Assets::firstLevelLeft; sf::Sprite Assets::firstLevelRight; sf::Sprite Assets::firstLevelRightt;
sf::Sprite Assets::blankTile; sf::Sprite Assets::background; sf::Sprite Assets::title;
sf::Sprite Assets::secondLevel; sf::Sprite Assets::secondLevelLeft; sf::Sprite Assets::secondLevelRight; sf::Sprite Assets::thirdLevel;
sf::Sprite Assets::thirdLevelLeft; sf::Sprite Assets::thirdLevelRight; sf::Sprite Assets::fourthLevel; sf::Sprite Assets::fourthLevelLeft;
sf::Sprite Assets::fourthLevelRight; sf::Sprite Assets::diploma; sf::Sprite Assets::hat; sf::Sprite Assets::instruction;

sf::Texture Assets::text1[2];sf::Texture Assets::text2[2];sf::Texture Assets::text3[2];sf::Texture Assets::text4[2];sf::Texture Assets::text5[2];
sf::Texture Assets::text6[2]; sf::Texture Assets::Face[12];  sf::Texture Assets::PlayerStand[2]; sf::Texture Assets::PlayerLeft[4];
sf::Texture Assets::PlayerRight[4]; sf::Texture Assets::PlayerJump[1]; sf::Texture Assets::PlayerFall[2]; sf::Texture Assets::PlayerJumpLeft[2];
sf::Texture Assets::PlayerJumpRight[2]; sf::Texture Assets::PlayerFallLeft[2]; sf::Texture Assets::PlayerFallRight[2]; sf::Texture Assets::door[2];
sf::Texture Assets::connect[2]; sf::Texture Assets::clear[2];

void Assets::Init()
{
	// Loading images to textures
	menuTexture.loadFromFile("Resources/Menu.jpg"); 
	menuTexture2.loadFromFile("Resources/Napisy.png", sf::IntRect(1320, 0, 660, 616));
	leftWallTexture.loadFromFile("Resources/Wall.png", sf::IntRect(0, 0, 320, 1600));
	rightWallTexture.loadFromFile("Resources/Wall.png", sf::IntRect(324, 0, 320, 1600));
	midWallTexture.loadFromFile("Resources/Wall.png", sf::IntRect(640, 0, 320, 1600));
	backgroundTexture.loadFromFile("Resources/Background.png", sf::IntRect(0, 0, 1056, 3650));
	point.loadFromFile("Resources/sheet.png", sf::IntRect(0, 270, 125, 50));
	instructionTexture.loadFromFile("Resources/Napisy.png", sf::IntRect(0, 816, 1400, 900));
	titleTexture.loadFromFile("Resources/Title.png", sf::IntRect(0, 0, 850,750));

	blankTexture.loadFromFile("Resources/sheet.png", sf::IntRect(0, 128, 64, 64));
	firstLevelTexture.loadFromFile("Resources/sheet.png", sf::IntRect(64, 0, 64, 64));
	firstLevelTextureLeft.loadFromFile("Resources/sheet.png", sf::IntRect(0, 0, 64, 64));
	firstLevelTextureRight.loadFromFile("Resources/sheet.png", sf::IntRect(128, 0, 64, 64));

	secondLevelTexture.loadFromFile("Resources/sheet.png", sf::IntRect(64, 65, 64, 64));
	secondLevelTextureLeft.loadFromFile("Resources/sheet.png", sf::IntRect(0, 65, 64, 64));
	secondLevelTextureRight.loadFromFile("Resources/sheet.png", sf::IntRect(128, 65, 64, 64));

	thirdLevelTexture.loadFromFile("Resources/sheet.png", sf::IntRect(64, 128, 64, 64));
	thirdLevelTextureLeft.loadFromFile("Resources/sheet.png", sf::IntRect(0, 128, 64, 64));
	thirdLevelTextureRight.loadFromFile("Resources/sheet.png", sf::IntRect(128, 128, 64, 64));

	fourthLevelTexture.loadFromFile("Resources/sheet.png", sf::IntRect(64, 192, 64, 64));
	fourthLevelTextureLeft.loadFromFile("Resources/sheet.png", sf::IntRect(0, 192, 64, 64));
	fourthLevelTextureRight.loadFromFile("Resources/sheet.png", sf::IntRect(128, 192, 64, 64));

	diplomaTexture.loadFromFile("Resources/sheet.png", sf::IntRect(200, 0, 160, 420));
	hatTexture.loadFromFile("Resources/sheet.png", sf::IntRect(400, 0, 290, 220));

	// Loading images to tables of textures (for animations and buttons)
	text1[0].loadFromFile("Resources/Napisy.png", sf::IntRect(0, 0, 660, 100));
	text1[1].loadFromFile("Resources/Napisy.png", sf::IntRect(660, 0, 660, 100));
	text2[0].loadFromFile("Resources/Napisy.png", sf::IntRect(0, 100, 660, 100));
	text2[1].loadFromFile("Resources/Napisy.png", sf::IntRect(660, 100, 660, 100));
	text3[0].loadFromFile("Resources/Napisy.png", sf::IntRect(0, 200, 660, 100));
	text3[1].loadFromFile("Resources/Napisy.png", sf::IntRect(660, 200, 660, 100));
	text4[0].loadFromFile("Resources/Napisy.png", sf::IntRect(0, 300, 660, 100));
	text4[1].loadFromFile("Resources/Napisy.png", sf::IntRect(660, 300, 660, 100));
	text5[0].loadFromFile("Resources/Napisy.png", sf::IntRect(0, 400, 660, 100));
	text5[1].loadFromFile("Resources/Napisy.png", sf::IntRect(660, 400, 660, 100));
	text6[0].loadFromFile("Resources/Napisy.png", sf::IntRect(0, 516, 660, 100));
	text6[1].loadFromFile("Resources/Napisy.png", sf::IntRect(660, 516, 660, 100));

	connect[0].loadFromFile("Resources/Napisy.png", sf::IntRect(0, 616, 330, 100));
	connect[1].loadFromFile("Resources/Napisy.png", sf::IntRect(330, 616, 330, 100));

	clear[0].loadFromFile("Resources/Napisy.png", sf::IntRect(660, 616, 330, 100));
	clear[1].loadFromFile("Resources/Napisy.png", sf::IntRect(990, 616, 330, 100));

	Face[0].loadFromFile("Resources/Student_Face.png", sf::IntRect(0, 0, 315, 215));
	Face[1].loadFromFile("Resources/Student_Face.png", sf::IntRect(0, 0, 315, 215));
	Face[2].loadFromFile("Resources/Student_Face.png", sf::IntRect(0, 420, 310, 210));
	Face[3].loadFromFile("Resources/Student_Face.png", sf::IntRect(0, 205, 315, 215));
	Face[4].loadFromFile("Resources/Student_Face.png", sf::IntRect(0, 205, 315, 215));
	Face[5].loadFromFile("Resources/Student_Face.png", sf::IntRect(0, 420, 310, 210));
	Face[6].loadFromFile("Resources/Student_Face.png", sf::IntRect(305, 0, 315, 215));
	Face[7].loadFromFile("Resources/Student_Face.png", sf::IntRect(305, 0, 315, 215));
	Face[8].loadFromFile("Resources/Student_Face.png", sf::IntRect(310, 420, 310, 210));
	Face[9].loadFromFile("Resources/Student_Face.png", sf::IntRect(305, 205, 315, 215));
	Face[10].loadFromFile("Resources/Student_Face.png", sf::IntRect(305, 205, 315, 215));
	Face[11].loadFromFile("Resources/Student_Face.png", sf::IntRect(310, 420, 310, 210));

	PlayerStand[0].loadFromFile("Resources/Player.png", sf::IntRect(0, 0, 100, 135));
	PlayerStand[1].loadFromFile("Resources/Player.png", sf::IntRect(100, 0, 100, 135));

	PlayerLeft[0].loadFromFile("Resources/Player.png", sf::IntRect(200, 270, 100, 135));
	PlayerLeft[1].loadFromFile("Resources/Player.png", sf::IntRect(0, 270, 100, 135));
	PlayerLeft[2].loadFromFile("Resources/Player.png", sf::IntRect(100, 270, 100, 135));
	PlayerLeft[3].loadFromFile("Resources/Player.png", sf::IntRect(0, 270, 100, 135));

	PlayerRight[0].loadFromFile("Resources/Player.png", sf::IntRect(0, 135, 100, 135));
	PlayerRight[1].loadFromFile("Resources/Player.png", sf::IntRect(200, 135, 100, 135));
	PlayerRight[2].loadFromFile("Resources/Player.png", sf::IntRect(100, 135, 100, 135));
	PlayerRight[3].loadFromFile("Resources/Player.png", sf::IntRect(200, 135, 100, 135));

	PlayerJump[0].loadFromFile("Resources/Player.png", sf::IntRect(0, 405, 100, 135));
	PlayerJump[1].loadFromFile("Resources/Player.png", sf::IntRect(100, 405, 100, 135));
	
	PlayerFall[0].loadFromFile("Resources/Player.png", sf::IntRect(200, 405, 100, 135));
	PlayerFall[1].loadFromFile("Resources/Player.png", sf::IntRect(100, 405, 100, 135));
	
	PlayerJumpLeft[0].loadFromFile("Resources/Player2.png", sf::IntRect(200, 0, 100, 135));
	PlayerJumpLeft[1].loadFromFile("Resources/Player2.png", sf::IntRect(200, 0, 100, 135));

	PlayerJumpRight[0].loadFromFile("Resources/Player2.png", sf::IntRect(0, 0, 100, 135));
	PlayerJumpRight[1].loadFromFile("Resources/Player2.png", sf::IntRect(0, 0, 100, 135));

	PlayerFallLeft[0].loadFromFile("Resources/Player2.png", sf::IntRect(300, 0, 100, 135));
	PlayerFallLeft[1].loadFromFile("Resources/Player2.png", sf::IntRect(300, 0, 100, 135));

	PlayerFallRight[0].loadFromFile("Resources/Player2.png", sf::IntRect(100, 0, 100, 135));
	PlayerFallRight[1].loadFromFile("Resources/Player2.png", sf::IntRect(100, 0, 100, 135));

	door[0].loadFromFile("Resources/sheet.png", sf::IntRect(0, 320, 60, 90));
	door[1].loadFromFile("Resources/sheet.png", sf::IntRect(100, 320, 60, 90));


	// Loading textures to Sprites and cropping them if needed -> making ready to render objects
	menu.setTexture(menuTexture);
	menu2.setTexture(menuTexture2);
	menu2.setPosition(890, 280);
	leftWall.setTexture(leftWallTexture);
	rightWall.setTexture(rightWallTexture);
	midWall.setTexture(midWallTexture);
	leftWall.setPosition(1296,0);
	rightWall.setPosition(168, 0);
	leftWall.setScale(0.425f, 1);
	rightWall.setScale(0.525f, 1);
	midWall.setScale(0.525f,1);
	background.setTexture(backgroundTexture);
	background.setPosition(288, 415*48*0.3 );
	diploma.setTexture(diplomaTexture);
	diploma.setScale(1.5, 1.5);
	diploma.setPosition(350,200);
	hat.setTexture(hatTexture);
	hat.setScale(2, 2);
	hat.setPosition(780,30);
	instruction.setTexture(instructionTexture);
	instruction.setPosition(150, 30);
	title.setTexture(titleTexture);
	title.setPosition(20, 50);

	blankTile.setTexture(blankTexture);
	firstLevel.setTexture(firstLevelTexture);
	firstLevelLeft.setTexture(firstLevelTextureLeft);
	firstLevelRight.setTexture(firstLevelTextureRight);
	firstLevelRightt.setTexture(firstLevelTextureRight);
	secondLevel.setTexture(secondLevelTexture);
	secondLevelLeft.setTexture(secondLevelTextureLeft);
	secondLevelRight.setTexture(secondLevelTextureRight);
	thirdLevel.setTexture(thirdLevelTexture);
	thirdLevelLeft.setTexture(thirdLevelTextureLeft);
	thirdLevelRight.setTexture(thirdLevelTextureRight);
	fourthLevel.setTexture(fourthLevelTexture);
	fourthLevelLeft.setTexture(fourthLevelTextureLeft);
	fourthLevelRight.setTexture(fourthLevelTextureRight);
}
