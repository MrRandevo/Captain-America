#include "Aquaman.h"
#include "Board.h"
Aquaman::~Aquaman()
{
	 
}

Aquaman::Aquaman(Board* FBoard)
	:Hero(FBoard)
{
	Star = new AStar(FBoard);

	Star->player.x = 0;
	Star->player.y = 0;
	Star->dest.x = 0;
	Star->dest.y = 0;

	this->setAttributes(100, 40, 0.35);
	this->changeStats(40, 1);
	 
	enemy = false;
	obstacle = false;
	skill_help = NULL;
	foe = NULL;
}
void Aquaman::skill()
{
	this->changeHP(-10);
}

void Aquaman::update(const float& dt)
{
	this->elapsed2 = dt;
	this->skill2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float skill_dt = skill2 - skill1;
	float tem = this->getStats().speed_attack;

	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Aquamana";
		this->attack(foe);
		this->elapsed1 = dt;
	}
	else if ((enemy == true && sub_dt < tem) )
	{ 
	}

	else if (type == OBJ_WATER && skill_dt > 10)
	{
		this->skill();
		this->skill1 = dt;
	}
	 
	else
	{
		if ( type == OBJ_WATER)
		{
			this->changeSpeed(1.6);
			this->move(cords);
			this->changeSpeed(0.625); 
		}
		else
		{
			this->move(cords);
		}
	} 
	enemy = false; 
	type = OBJ_NONE;
}
