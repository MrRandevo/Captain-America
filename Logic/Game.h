#pragma once
#include "State.h"
#include "MainMenu.h"
#include "ChooseTeam.h"
class Game
{
private:
	//Atrybuty
	sf::RenderWindow *window;
	sf::Event Event;
	sf::Clock dtClock;
	std::stack <State*> states;  
	  
	//Funkcje do inicjalizacji
	void initWindow();
	void initStates();
  
public:
	//Konstruktor
	float dt;

	Game();
	//Destruktor
	virtual ~Game();

	//Funkcje
	void run();

	//Drukowanie
	void render();

	//Aktualizcja
	void updateDt();
	void update();
	void updateSFML();
	
	 
};
 

 