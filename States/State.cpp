#include "State.h"

// Inicjalizacja statycznego atrybutu

std::vector<std::string> State::name;
 
State::State(sf::RenderWindow* window, std::stack <State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

 
State::~State()
{
}

 
const bool& State::getQuit() const
{
	return this->quit;
}
 

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords
					(sf::Mouse::getPosition(*this->window));
}

 
 