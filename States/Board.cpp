#include "Board.h"
#include "Object.h"

void Board::initFonts()
{
	if (!this->font.loadFromFile("Fonts\\arial.ttf"))
	{
		std::cout << "Could not load";
	} 
}

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
		/*
		if (it == "Aquaman")
		{
			Objects.push_back(new Aquaman());
			GObjects.push_back(new GAquaman(Objects[i]));
		}
		if (it == "Flash")
		{
			Objects.push_back(new Flash());
			GObjects.push_back(new GFlash(Objects[i]));
		}
		if (it == "GreenArrow")
		{
			Objects.push_back(new GreenArrow());
			GObjects.push_back(new GGreenArrow(Objects[i]));
		}
		if (it == "Darkseid")
		{
			Objects.push_back(new Darkseid());
			GObjects.push_back(new GDarkseid(Objects[i]));
		}
		if (it == "CaptainCold")
		{
			Objects.push_back(new CaptainCold());
			GObjects.push_back(new GCaptainCold(Objects[i]));
		}
		if (it == "Deathstroke")
		{
			Objects.push_back(new Deathstroke());
			GObjects.push_back(new GDeathstroke(Objects[i]));
		}
		if (it == "Joker")
		{
			Objects.push_back(new Joker());
			GObjects.push_back(new GJoker(Objects[i]));
		}
		if (it == "LexLuthor")
		{
			Objects.push_back(new LexLuthor());
			GObjects.push_back(new GLexLuthor(Objects[i]));
		}
		if (it == "PoisonIvy")
		{
			Objects.push_back(new PoisonIvy());
			GObjects.push_back(new GPoisonIvy(Objects[i]));
		}
		*/
		i++; 
	}

	for (int k = 0; k < name.size(); k++)
	{
		if (k < 4)
		{
			Objects[k]->setCoordinates(30, 50 + (k * 120));
			Objects[k]->Team = true;
		}

		if (k > 3)
		{
			Objects[k]->setCoordinates(900, 50 + ((k - 4) * 120));
			Objects[k]->Team = false;
		}
	}
}

Board::Board(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{ 
	this->Map = new TileMap(this);
	 
	this->initFonts();  
	this->initHeroes();	
	
}

Board::~Board()
{
	Objects.clear();
	GObjects.clear();
	Map = NULL;
	delete Map;
}
 
void Board::update(const float& dt)
{ 
	this->updateHeroes(dt);
	this->updateMap(dt);
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
				Objects[i]->enemy = Objects[i]->SomethingIsNear(Objects[j], 50.0); 
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
