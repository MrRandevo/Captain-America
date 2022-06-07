#include "Hero.h" 
struct statistics;

//Konstruktor
Hero::Hero(Board* FBoard)
	:Object(FBoard)
{  
	this->HeroState = HRO_IDLE;
	this->elapsed1 = 0;
	this->elapsed2 = 0;
	this->skill1 = 0;
	this->skill2 = 0;
}

//Destruktor
Hero::~Hero()
{
	delete Star;
}
void Hero::changeStats(float strength , float speed_attack )
{
	this->stats.strength = strength; 
	this->stats.speed_attack = speed_attack;
 
}

statistics Hero::getStats()
{
	return this->stats;
}
 
void Hero::move(Vector2f& originPosition)
{ 
	if ((Star->player.x == Star->dest.x) && (Star->player.y == Star->dest.y))
	{
		Star->player.x = (this->getCoordinates().Coordinate_X - 25) / 50;
		Star->player.y = (this->getCoordinates().Coordinate_Y - 25)/ 50;
		  
		do
		{
			this->randomCoords();
			this->findPath();
		} while (!Star->isValid(Star->dest.x, Star->dest.y) );
 
	}

	Vector2f temp = { 25 + (path.front().x) * 50, 25 + (path.front().y) * 50 };
	 
	if ((cords.Coordinate_X + 0.32 > temp.Coordinate_X) && (cords.Coordinate_X - 0.32 < temp.Coordinate_X) &&
		(cords.Coordinate_Y + 0.32 > temp.Coordinate_Y) && (cords.Coordinate_Y - 0.32 < temp.Coordinate_Y))
	{ 
		setCoordinates((temp.Coordinate_X - 25)/50,(temp.Coordinate_Y - 25)/50);
		Star->player.x = (temp.Coordinate_X - 25) / 50;
		Star->player.y = (temp.Coordinate_Y - 25) / 50; 
		if (!path.empty())
		{
			path.erase(path.begin());
		}
	}

	float dir_x = 0.0;
	float dir_y = 0.0;

	if (temp.Coordinate_X > cords.Coordinate_X)
	{
		dir_x = 1.0;
	}
	else if(temp.Coordinate_X < cords.Coordinate_X)
	{
		dir_x = -1.0;
	}
	else
	{
		dir_x = 0.0;
	}

	if (temp.Coordinate_Y > cords.Coordinate_Y)
	{
		dir_y = 1.0;
	}
	else if (temp.Coordinate_Y < cords.Coordinate_Y)
	{
		dir_y = -1.0;
	}
	else
	{
		dir_y = 0.0;
	}

	Vector2f temp2 = {dir_x, dir_y};

	originPosition = (temp2 * (this->getAttributes().speed)) + originPosition;
}

void Hero::findPath()
{
	this->path = Star->aStar(this->Star->player, this->Star->dest);
}

void Hero::randomCoords()
{
	Star->dest.x = rand() % 19;
	Star->dest.y = rand() % 12;
}

void Hero::attack(Object* enemy)
{
	float armour = enemy->getAttributes().armour;
	float health = enemy->getAttributes().health;
	float strength = this->getStats().strength;

	float damage = strength * (1 - (armour / 100)); 
	enemy->changeHP(damage); 
}
 