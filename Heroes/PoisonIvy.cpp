#include "PoisonIvy.h"

PoisonIvy::PoisonIvy(Board* FBoard)
	:Hero(FBoard)
{
	Star = new AStar(FBoard);

	Star->player.x = 0;
	Star->player.y = 0;
	Star->dest.x = 0;
	Star->dest.y = 0;

	this->setAttributes(100, 50, 0.5);
	this->changeStats(20, 1);
	enemy = false;
	obstacle = false;
	skill_help = NULL;
	foe = NULL;
}

PoisonIvy::~PoisonIvy()
{
}

void PoisonIvy::skill()
{
}

void PoisonIvy::update(const float& dt)
{
	this->elapsed2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float tem = this->getStats().speed_attack;


	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Supermana";
		this->attack(foe);
		this->elapsed1 = dt;
	}
	else if (enemy == true && sub_dt < tem)
	{

	} 
	else
	{
		if (type == OBJ_WATER)
		{
			this->changeSpeed(0.5);
			this->move(this->cords);
			this->changeSpeed(2);
		}
		else
		{
			this->move(this->cords);
		}
	}

	enemy = false; 
	type = OBJ_NONE;
}
