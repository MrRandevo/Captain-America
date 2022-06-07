#include "Flash.h"
#include "Board.h"
Flash::Flash(Board* FBoard)
	:Hero(FBoard)
{
	Star = new AStar(FBoard);

	Star->player.x = 0;
	Star->player.y = 0;
	Star->dest.x = 0;
	Star->dest.y = 0;

	this->setAttributes(100, 40, 0.55);
	this->changeStats(14, 0.3);
	 
	enemy = false;
	obstacle = false;
	skill_help = NULL;
	foe = NULL;
}

Flash::~Flash()
{
}

void Flash::skill()
{
}

void Flash::update(const float& dt)
{
	this->elapsed2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float tem = this->getStats().speed_attack;

	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Flasha";
		this->attack(foe);
		this->elapsed1 = dt;
	}
	else if (sub_dt < tem)
	{
	}
 
	else
	{
		if ( type == OBJ_WATER)
		{
			this->changeSpeed(0.5);
			this->move(cords);
			this->changeSpeed(2);

		}
		else
		{
			this->move(cords);
		}
	}
	enemy = false; 
	type = OBJ_NONE;
}
