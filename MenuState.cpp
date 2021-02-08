#include "MenuState.h"

// Constructors and destructor

MenuState::MenuState() {
	Window = nullptr;
}

// Initializing

void MenuState::Init(sf::RenderWindow* Window) {
	operatingMode = 0;

		// Windows init
	this->Window = Window;

		//Mouse init
	mouse.Init(this->Window, 10, 10);

		// Animations init
	faceAnim.Init(170,12,Assets::Face);
	face.setTexture( faceAnim.getFrames() [faceAnim.getIndex()] );
	face.setPosition(630, 80);
	face.setScale(1.5f,1.5f);

		// Buttons init
	start.setGraphics(Assets::text1);
	multiplayer.setGraphics(Assets::text2);
	instruction.setGraphics(Assets::text3);
	score.setGraphics(Assets::text5);
	exit.setGraphics(Assets::text6);
	door.setGraphics(Assets::door);

	//Text
	font.loadFromFile("Resources/Fonts/Zeyada.ttf");
	text.setFont(font);
	text.setCharacterSize(70);
	text.setFillColor(sf::Color(255, 255, 255));
	text.setOutlineThickness(4.f);
	text.setOutlineColor(sf::Color(0, 0, 0));
}

// Functions

void MenuState::update() {
	pollEvents();	
	faceAnim.update();
	face.setTexture(faceAnim.getFrames()[faceAnim.getIndex()]);
}

void MenuState::render() {
	this->Window->clear();

	// Drawing background
	this->Window->draw(Assets::menu);
	if(operatingMode!=1)
		this->Window->draw(Assets::menu2);

	// Drawing all the buttons
	if (operatingMode == 0) {
		this->Window->draw(start.getButton(mouse, Window));
		this->Window->draw(multiplayer.getButton(mouse, Window));
		this->Window->draw(instruction.getButton(mouse, Window));
		this->Window->draw(score.getButton(mouse, Window));
		this->Window->draw(exit.getButton(mouse, Window));
		this->Window->draw(Assets::title);
	}
	if (operatingMode == 1) {
		this->Window->draw(Assets::instruction);
		this->Window->draw(door.getButton(mouse, Window));
	}
	if (operatingMode == 2) {
		text.setString(L"Twoje najlepsze wyniki : ");
		text.setPosition(850, 100);
		this->Window->draw(text);
		for (int i = 0; i < 10; i++) {
			text.setString(std::to_string(i+1) + ".");
			text.setPosition(850 , 200 + i*60);
			this->Window->draw(text);			
			text.setString(scores[i] + " Ects'ów");
			text.setPosition(1200, 200 + i*60);
			this->Window->draw(text);
			this->Window->draw(door.getButton(mouse, Window));
		}
	}
	// Drawing animation
	this->Window->draw(face);
	//this->Window->draw(Assets::title);
	this->Window->display();
}

void MenuState::pollEvents() {
	if (operatingMode == 0) {
		while (this->Window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				this->Window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (start.ifPointed(mouse, Window))
						State::setState(table[1]);
					if (multiplayer.ifPointed(mouse, Window))
						State::setState(table[3]);
					if (instruction.ifPointed(mouse, Window)) {
						face.setPosition(0, 0);
						operatingMode = 1;
					}				
					if (score.ifPointed(mouse, Window)) {
						Utils::loadFileAsStringArray("Resources/Scores/score.txt",scores);
						Assets::menu2.setScale(1.3, 1.3);
						Assets::menu2.setPosition(680, 90);
						face.setPosition(440, 0);
						operatingMode = 2;
					}		
					if (exit.ifPointed(mouse, Window))
						this->Window->close();
				}
				break;
			default:
				break;
			}
		}
	}
	if (operatingMode == 1) {
		while (this->Window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				this->Window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (door.ifPointed(mouse, Window)) {
						Assets::menu2.setPosition(890, 280);
						Assets::menu2.setScale(1,1);
						face.setPosition(630, 80);
						operatingMode = 0;
					}
				}
				break;
			default:
				break;
			}
		}
	}
	if (operatingMode == 2) {
		while (this->Window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				this->Window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (door.ifPointed(mouse, Window)) {
						Assets::menu2.setPosition(890, 280);
						Assets::menu2.setScale(1, 1);
						face.setPosition(630, 80);
						operatingMode = 0;
					}
				}
				break;
			default:
				break;
			}
		}
	
	}
}