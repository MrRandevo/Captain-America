#include "Board.h"
#include "Object.h"
#include "MainMenu.h"

void Board::initFonts()
{
	if (!this->font.loadFromFile("Fonts\\arial.ttf"))
	{
		std::cout << "Could not load";
	} 
}

//void Board::initTextures()
//{
//	this->Textures["GreenArrowSheet"] = new sf::Texture();
//	Textures["GreenArrowSheet"]->loadFromFile("Sprite\\GreenArrowSheet.png");
//
//	this->Textures["BatmanWalk"] = new sf::Texture();
//	Textures["BatmanWalk"]->loadFromFile("Sprite\\BatmanFight.png");
//}

void Board::initHeroes()
{
	int i = 0;
	for (auto& it : name)
	{
		if (it == "Batman")
		{
			Objects.push_back(new Batman(this));
			GObjects.push_back(new GBatman(Objects[i])); 
		}

		if (it == "Superman")
		{
			Objects.push_back(new Superman(this));
			GObjects.push_back(new GSuperman(Objects[i]));
		}

		if (it == "WonderWoman")
		{
			Objects.push_back(new WonderWoman(this));
			GObjects.push_back(new GWonderWoman(Objects[i]));
		}
		 
		if (it == "Aquaman")
		{
			Objects.push_back(new Aquaman(this));
			GObjects.push_back(new GAquaman(Objects[i]));
		}
		 
		if (it == "Flash")
		{
			Objects.push_back(new Flash(this));
			GObjects.push_back(new GFlash(Objects[i]));
		}
		 
		if (it == "GreenArrow")
		{
			Objects.push_back(new GreenArrow(this));
			GObjects.push_back(new GGreenArrow( Objects[i] ));
		} 

		if (it == "Joker")
		{
			Objects.push_back(new Joker(this));
			GObjects.push_back(new GJoker(Objects[i]));
		}
		 
		if (it == "Darkseid")
		{
			Objects.push_back(new Darkseid(this));
			GObjects.push_back(new GDarkseid(Objects[i]));
		}
		 
		if (it == "CaptainCold")
		{
			Objects.push_back(new CaptainCold(this));
			GObjects.push_back(new GCaptainCold(Objects[i]));
		}
		 
		if (it == "Deathstroke")
		{
			Objects.push_back(new Deathstroke(this));
			GObjects.push_back(new GDeathstroke(Objects[i]));
		} 
		
		if (it == "LexLuthor")
		{
			Objects.push_back(new LexLuthor(this));
			GObjects.push_back(new GLexLuthor(Objects[i]));
		}
		if (it == "PoisonIvy")
		{
			Objects.push_back(new PoisonIvy(this));
			GObjects.push_back(new GPoisonIvy(Objects[i]));
		}
		
		i++; 
	}

	for (int k = 0; k < name.size(); k++)
	{
		if (k < 4)
		{
			Objects[k]->setCoordinates(0, 1+2*k);
			Objects[k]->Team = true;
			GObjects[k]->health.setFillColor(sf::Color::Red);
		}

		if (k > 3)
		{
			Objects[k]->setCoordinates(19, 1+2*(k-4));
			Objects[k]->Team = false;
			GObjects[k]->health.setFillColor(sf::Color::Blue);
		}
	}
}

Board::Board(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{  
	this->initFonts();  
	//this->initTextures();
	this->initHeroes();	

	this->Map = new TileMap(this);
	
}

Board::~Board()
{
	Objects.clear();
	GObjects.clear();
	Map = NULL;
	delete Map;

	auto it = this->Textures.begin();
	for (it = Textures.begin(); it != this->Textures.end(); ++it)
	{
		delete it->second;
	}
}
 
void Board::update(const float& dt)
{ 
	this->updateHeroes(dt);
	this->updateMap(dt);
	this->checkForEnd();
} 

void Board::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	Map->render(target);
	this->renderHeroes(target);
}

void Board::updateHeroes(const float& dt)
{
	for (int i = 0; i < Objects.size(); i++)
	{
		if (Objects[i]->getAttributes().health == 0)
		{
			this->GObjects.erase(this->GObjects.begin() + i);
			this->Objects.erase(this->Objects.begin() + i);
			break;
		}

		for (int j = 0; j < Objects.size(); j++)
		{ 
			if ((i != j) && (Objects[i]->Team != Objects[j]->Team))
			{
				Objects[i]->enemy = Objects[i]->SomethingIsNear(Objects[j], 60.0); 
				if (Objects[i]->enemy == true)
				{
					Objects[i]->foe = Objects[j];
					break;
				} 
			}
		}
		Objects[i]->update(dt);
		GObjects[i]->update(dt);
	}
}

void Board::renderHeroes(sf::RenderTarget* target)
{
	for (int i = 0; i < GObjects.size(); i++)
		GObjects[i]->draw(target);
}

void Board::updateMap(const float& dt)
{
	this->Map->update(dt);
}

void Board::checkForEnd()
{
	int licz1 = 0;
	int licz2 = 0;
	for (int i = 0; i < Objects.size(); i++)
	{
		if (Objects[i]->Team == true)
		{
			licz1++;
		}
		if (Objects[i]->Team == false)
		{
			licz2++;
		}

	}

	if ((licz1 == 0) || (licz2 == 0) )
	{ 
		sf::Clock clk;
		float delta = clk.getElapsedTime().asSeconds();
		while (delta < 3.0)
		{
			delta = clk.getElapsedTime().asSeconds();
		}
		this->states->pop();
		this->states->push(new MainMenu(this->window, this->states));
	} 
}
