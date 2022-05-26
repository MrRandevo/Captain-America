#include "State.h"

std::vector<std::string> State::name;

//Konstruktor
State::State(sf::RenderWindow* window, std::stack <State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

//Destruktor
State::~State()
{
}

//zmienna do sprawdzania czy uzytkownik chce opuscic program
const bool& State::getQuit() const
{
	return this->quit;
}
 
//Aktualizacja pozycji myszki
void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords
					(sf::Mouse::getPosition(*this->window));
}

 
 