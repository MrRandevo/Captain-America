#include "Game.h"
  
 //Inicjalizacja okna
void Game::initWindow()
{
	sf::VideoMode window_bounds(1000, 600);
	this->window = new sf::RenderWindow(window_bounds, "CAPTAIN AMERICA");
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}

//Inicjalizacja stanów programu
void Game::initStates()
{
	  states.push(new MainMenu (this->window,&this->states)); 
}
 
//Konstruktor
Game::Game()
{
	this->initWindow(); 
	this->initStates();
}

//Destructor
Game::~Game()
{
	delete this->window;
	
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//Akutalizacja czasu
void Game::updateDt()
{
	this->dt = this->dtClock.getElapsedTime().asSeconds(); 
}

//Aktualizcja gry
void Game::update()
{
	this->updateSFML();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			 
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->window->close();
	}
}

//aktualizacja eventow
void Game::updateSFML()
{
	while (this->window->pollEvent(this->Event))
	{
		if (this->Event.type == sf::Event::Closed)
			this->window->close();

		if (this->Event.type == sf::Event::KeyPressed)
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				this->window->close();
	}
}
 
//Drukowanie na ekran
void Game::render()
{
	this->window->clear();
	
	if (!this->states.empty())
		this->states.top()->render();
	this->window->display();	 
}
 
//Sprawdzanie czy program jest otwarty
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

 