#include "MainMenu.h"
#include "Chooseteam.h"

//£adowanie czcionki
void MainMenu::initFonts()				 
{
	if (!this->font.loadFromFile("Fonts\\arial.ttf"))
	{
		std::cout << "Could not load"; 
	}
}	  
 
//Tworzenie przyciskow  
void MainMenu::initButtons()
{
	this->buttons["START"] = new Button(430, 430, 140, 40, &font, "NEW GAME",
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200));

	this->buttons["EXIT"] = new Button(430, 480, 140, 40, &font, "QUIT",
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)); 
}

//Konstruktor 
MainMenu::MainMenu(sf::RenderWindow* window, std::stack <State*>* states)
	:State(window, states )
{	
	this->initFonts(); 
	this->initButtons();
   
 	this->texture.loadFromFile("Textures\\DC_Wallpaper.jpg");
	this->sprite.setTexture(texture);
}

//Destruktor
MainMenu::~MainMenu()
{
	auto it = this->buttons.begin();
	for (it = buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}
  
//Aktualizacja obiektu
void MainMenu::update(const float& dt)
{ 
	this->updateMousePosition();
	this->updateButtons(); 

	//Wybierz druzyne
	if (this->buttons["START"]->isPressed())
	{
		this->states->pop();
		this->states->push(new ChooseTeam(this->window,this->states));
	} 
	//Opusc gre
	if (this->buttons["EXIT"]->isPressed())
	{
		this->quit = true;
	} 
}

//Drukowanie na ekran
void MainMenu::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(sprite);
	this->renderButtons(target);
}

//Aktualizacja przyciskow
void MainMenu::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

//Drukowanie przyciskow
void MainMenu::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

 