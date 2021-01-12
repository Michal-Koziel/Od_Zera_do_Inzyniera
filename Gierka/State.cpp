#include "State.h"


// Constructors and destructor

State::State() {
}

// Static variable and functions

State* State::currentState = nullptr;

State* State::getState() {
	return currentState;
}

void State::setState(State* state) {
	currentState = state;
}

// Functions

void State::InitTable(State* tab[5]) {
	table[0] = tab[0];
	table[1] = tab[1];
	table[2] = tab[2];
	table[3] = tab[3];
	table[4] = tab[4];
}

// Virtual Functions

void State::update() {

}

void State::render() {

}
