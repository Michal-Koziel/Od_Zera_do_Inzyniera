#include "IpState.h"
//#include <iostream>

std::string  IpState::ipAdress;

// Constructors and destructor

IpState::IpState() {
	Window = nullptr;
}

// Initializing

void IpState::Init(sf::RenderWindow* Window) {
	this->Window = Window;

	string = "";
	font.loadFromFile("Resources/Fonts/Zeyada.ttf");
	text.setFont(font);
	text.setCharacterSize(70);
	text.setFillColor(sf::Color(255, 255, 255));
	text.setOutlineThickness(4.f);
	text.setOutlineColor(sf::Color(0, 0, 0));
	text.setPosition(500, 400);
	text.setString(string);

	text2 = text;
	text2.setCharacterSize(50);
	text2.setPosition(460, 250);
	text2.setString(L"Podaj adres ip z którym chcesz siê po³¹czyæ : ");

	//button init
	mouse.Init(this->Window, 10, 10);
	deleteButton.setGraphics(Assets::clear);
	returnButton.setGraphics(Assets::door);
	connectButton.setGraphics(Assets::connect);
}

// Functions

void IpState::update() {
	pollEvents();
	text.setString(string);
}

void IpState::render() {
	this->Window->clear();

	this->Window->draw(Assets::menu);
	Assets::menu2.setPosition(400, 200);
	Assets::menu2.setScale(1.3f,1);
	this->Window->draw(Assets::menu2);
	Assets::menu2.setPosition(890, 280);
	Assets::menu2.setScale(1,1);
	this->Window->draw(text);
	this->Window->draw(text2);
	this->Window->draw(deleteButton.getButton(mouse, Window));
	this->Window->draw(returnButton.getButton(mouse, Window));
	this->Window->draw(connectButton.getButton(mouse, Window));
	this->Window->display();
}

void IpState::pollEvents() {
	while (this->Window->pollEvent(event)) {

		if (event.type == sf::Event::Closed)
			this->Window->close();

		if (event.type == sf::Event::TextEntered) {
			string += event.text.unicode;
		}

		if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Left)) {
			if (deleteButton.ifPointed(mouse, Window))
				string = "";
			if (returnButton.ifPointed(mouse, Window))
				State::setState(table[0]);
			if (connectButton.ifPointed(mouse, Window)) {		
				IpState::ipAdress = string;
				string = "";
				State::setState(table[2]);
			}

		}

	}
}