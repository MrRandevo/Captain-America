#include "Batman.h"
#include "Board.h"

void Batman::addBomb( Board* FBoard)
{
	bomb = new Obstacle((this->getCoordinates().Coordinate_X -25)/50, (this->getCoordinates().Coordinate_Y -25) /50, FBoard);
	bomb->type = OBJ_BOMB;
	bomb->Team = (!this->Team);
}
  
Batman::Batman(Board* FBoard)
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
	bomb = NULL;  
}

Batman::~Batman()
{
	delete bomb;
}

void Batman::skill()
{
	this->addBomb(this->FBoard);

}

void Batman::update(const float& dt)
{
	this->elapsed2 = dt;
	this->skill2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float skill_dt = skill2 - skill1;
	float tem = this->getStats().speed_attack;
	
	if (bomb != NULL)
	{
		bomb->update(dt);
		if (bomb->isDestroyed == true)
		{
			bomb = NULL;
		}
	}
	 
	if (skill_dt > 15)
	{
		if (bomb == NULL)
		{ 
			this->skill();
			this->skill1 = dt;
			this->skill_help = 1;
		} 
	} 

	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Batmana";
		this->attack(foe); 
		this->elapsed1 = dt;
	}
	else if ((enemy == true && sub_dt < tem))
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
