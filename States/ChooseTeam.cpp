#include "Chooseteam.h"
#include "MainMenu.h"
#include "Board.h"

//Konstruktor 
ChooseTeam::ChooseTeam(sf::RenderWindow* window, std::stack <State*>* states)
	:State(window, states)
{
	this->initFonts(); 
	this->initButtons(); 
	this->initText();  
	this->initTextures();
	this->initImages(); 
}

//Destruktor
ChooseTeam::~ChooseTeam()
{
	auto i = this->buttons.begin();
	for (i = buttons.begin(); i != this->buttons.end(); ++i)
	{
		delete i->second;
	}

	auto it = this->Textures.begin();
	for (it = Textures.begin(); it != this->Textures.end(); ++it)
	{
		delete it->second;
	}

	auto ita = this->imags.begin();
	for (ita = imags.begin(); ita != this->imags.end(); ++ita)
	{
		delete ita->second;
	}
}

//£adowanie czcionki
void ChooseTeam::initFonts()
{
	if (!this->font.loadFromFile("Fonts\\arial.ttf"))
	{
			std::cout << "Could not load";
	}
}

//Inicjalizacja przyciskow
void ChooseTeam::initButtons()
{
	this->buttons["ZATWIERDZ"] = new Button(840, 550, 140, 40, &font, "ZATWIERDZ",
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200));

	this->buttons["WROC"] = new Button(20, 550, 140, 40, &font, "WROC",
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)); 
}

//Inicjalizacja obrazow
void ChooseTeam::initImages()
{  
	 
	this->imags["Batman"] = new Images(40, 40, 90, 120, Textures["Batman"]);
	this->imags["Superman"] = new Images(160, 40, 90, 120, Textures["Superman"]);
	this->imags["WonderWoman"] = new Images(280, 40, 90, 120, Textures["WonderWoman"]);
	this->imags["Aquaman"] = new Images(40, 170, 90, 120, Textures["Aquaman"]);
	this->imags["Flash"] = new Images(160, 170, 90, 120, Textures["Flash"]);
	this->imags["GreenArrow"] = new Images(280, 170, 90, 120, Textures["GreenArrow"]);
	
	this->imags["Joker"] = new Images(610, 40, 90, 120, Textures["Joker"]);
	this->imags["LexLuthor"] = new Images(740, 40, 90, 120, Textures["LexLuthor"]);
	this->imags["PoisonIvy"] = new Images(870, 40, 90, 120, Textures["PoisonIvy"]);
	this->imags["Deathstroke"] = new Images(610, 170, 90, 120, Textures["Deathstroke"]);
	this->imags["Darkseid"] = new Images(740, 170, 90, 120, Textures["Darkseid"]);
	this->imags["CaptainCold"] = new Images(870, 170, 90, 120, Textures["CaptainCold"]);

	this->imags["Team1a"] = new Images(280, 310, 90, 120, texture);
	this->imags["Team1b"] = new Images(390, 310, 90, 120, texture);
	this->imags["Team1c"] = new Images(500, 310, 90, 120, texture);
	this->imags["Team1d"] = new Images(610, 310, 90, 120, texture);

	this->imags["Team2a"] = new Images(280, 450, 90, 120, texture);
	this->imags["Team2b"] = new Images(390, 450, 90, 120, texture);
	this->imags["Team2c"] = new Images(500, 450, 90, 120, texture);
	this->imags["Team2d"] = new Images(610, 450, 90, 120, texture);
}

//Inicjalizacja tekstu
void ChooseTeam::initText()
{
	this->text1.setString("Heroes");
	this->text1.setFont(font);
	this->text1.setCharacterSize(20);
	this->text1.setPosition(165, 5);

	this->text2.setString("Villains");
	this->text2.setFont(font);
	this->text2.setCharacterSize(20);
	this->text2.setPosition(750, 10);

	this->text3.setString("Team One:");
	this->text3.setFont(font);
	this->text3.setCharacterSize(20);
	this->text3.setPosition(160, 360);

	this->text4.setString("Team Two:");
	this->text4.setFont(font);
	this->text4.setCharacterSize(20);
	this->text4.setPosition(160, 500);
}

//Wczytywanie tekstur
void ChooseTeam::initTextures()
{
	this->Textures["Batman"] = new sf::Texture();
	Textures["Batman"]->loadFromFile("Textures\\Batman.jpg");

	this->Textures["Superman"] = new sf::Texture();
	Textures["Superman"]->loadFromFile("Textures\\Superman.jpg");

	this->Textures["WonderWoman"] = new sf::Texture();
	Textures["WonderWoman"]->loadFromFile("Textures\\WonderWoman.jpg");

	this->Textures["Aquaman"] = new sf::Texture();
	Textures["Aquaman"]->loadFromFile("Textures\\Aquaman.jpg");

	this->Textures["Flash"] = new sf::Texture();
	Textures["Flash"]->loadFromFile("Textures\\Flash.jpg");

	this->Textures["GreenArrow"] = new sf::Texture();
	Textures["GreenArrow"]->loadFromFile("Textures\\GreenArrow.jpg");

	this->Textures["Darkseid"] = new sf::Texture();
	Textures["Darkseid"]->loadFromFile("Textures\\Darkseid.jpg");

	this->Textures["CaptainCold"] = new sf::Texture();
	Textures["CaptainCold"]->loadFromFile("Textures\\CaptainCold.jpg");

	this->Textures["Deathstroke"] = new sf::Texture();
	Textures["Deathstroke"]->loadFromFile("Textures\\Deathstroke.jpg");

	this->Textures["Joker"] = new sf::Texture();
	Textures["Joker"]->loadFromFile("Textures\\Joker.jpg");

	this->Textures["LexLuthor"] = new sf::Texture();
	Textures["LexLuthor"]->loadFromFile("Textures\\LexLuthor.jpg");

	this->Textures["PoisonIvy"] = new sf::Texture();
	Textures["PoisonIvy"]->loadFromFile("Textures\\PoisonIvy.jpg");

	this->texture = new sf::Texture();
	texture->create(180, 240);
}


void ChooseTeam::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->renderButtons(target);
	this->renderImages(target); 
	this->renderText(target);
}

void ChooseTeam::update(const float& dt)
{
	
	this->updateMousePosition();
	this->updateButtons();
	this->updateImages(); 

	// Po wcisnieciu przycisku, jesli druzyna zostala wybrana, gra zmienia stan na Plansze
	if (this->buttons["ZATWIERDZ"]->isPressed())
	{
		if (name.size() == 8)
		{
			this->states->pop();
			this->states->push(new Board(this->window, this->states));
		}
	}

	// Po wcisnieciu przycisku, wracamy do Menu glownego
	if (this->buttons["WROC"]->isPressed())
	{
		this->states->pop();
		this->states->push(new MainMenu(this->window, this->states));
		this->name.clear();
	}


	//Jesli, ktorys z przyciskow zostal wcisniety to bohaterzy sa zapisywani do gry
	if (name.size() < 8)
	{
		if (this->imags["Batman"]->isPressed())
		{
			name.push_back("Batman"); 
		}
		if (this->imags["Superman"]->isPressed())
		{
			name.push_back("Superman");
		}
		if (this->imags["WonderWoman"]->isPressed())
		{
			name.push_back("WonderWoman");
		}
		if (this->imags["Aquaman"]->isPressed())
		{
			name.push_back("Aquaman");
		}
		if (this->imags["Flash"]->isPressed())
		{
			name.push_back("Flash");
		}
		if (this->imags["GreenArrow"]->isPressed())
		{
			name.push_back("GreenArrow");
		}
		if (this->imags["Darkseid"]->isPressed())
		{
			name.push_back("Darkseid");
		}
		if (this->imags["CaptainCold"]->isPressed())
		{
			name.push_back("CaptainCold");
		}
		if (this->imags["Deathstroke"]->isPressed())
		{
			name.push_back("Deathstroke");
		} 
		if (this->imags["Joker"]->isPressed())
		{
			name.push_back("Joker");
		}
		if (this->imags["LexLuthor"]->isPressed())
		{
			name.push_back("LexLuthor");
		}
		if (this->imags["PoisonIvy"]->isPressed())
		{
			name.push_back("PoisonIvy");
		}
		 
		if (name.size() == 1)
		{
			this->imags["Team1a"]->changeTexture(Textures[name[0]]);
		}
		if (name.size() == 2)
		{
			this->imags["Team1b"]->changeTexture(Textures[name[1]]);
		}
		if (name.size() == 3)
		{
			this->imags["Team1c"]->changeTexture(Textures[name[2]]);
		}
		if (name.size() == 4)
		{
			this->imags["Team1d"]->changeTexture(Textures[name[3]]);
		} 
		if (name.size() == 5)
		{
			this->imags["Team2a"]->changeTexture(Textures[name[4]]);
		}
		if (name.size() == 6)
		{
			this->imags["Team2b"]->changeTexture(Textures[name[5]]);
		}
		if (name.size() == 7)
		{
			this->imags["Team2c"]->changeTexture(Textures[name[6]]);
		}
		if (name.size() == 8)
		{
			this->imags["Team2d"]->changeTexture(Textures[name[7]]);
		} 
	} 
}

void ChooseTeam::renderText(sf::RenderTarget* target)
{
	target->draw(text1);
	target->draw(text2);
	target->draw(text3);
	target->draw(text4);
}

void ChooseTeam::renderButtons(sf::RenderTarget* target)
{ 
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	} 
}

void ChooseTeam::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void ChooseTeam::renderImages(sf::RenderTarget* target)
{
	for (auto& it : this->imags)
	{
		it.second->render(target);
	}
}
 
void ChooseTeam::updateImages()
{ 
	for (auto& it : this->imags)
	{
		it.second->update(this->mousePosView);
	} 
}
 