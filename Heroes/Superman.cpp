#include "Superman.h"
#include "Board.h" 
Superman::Superman(Board* FBoard)
	:Hero(FBoard)
{
	Star = new AStar(FBoard);

	Star->player.x = 0;
	Star->player.y = 0;
	Star->dest.x = 0;
	Star->dest.y = 0;

	this->setAttributes(100, 50, 0.5);
	this->changeStats(20, 1 ); 
	enemy = false;
	obstacle = false;
	skill_help = NULL;
	foe = NULL; 
}

Superman::~Superman()
{
}

void Superman::skill()
{
	this->FBoard->Map->Gobj.erase(this->FBoard->Map->Gobj.begin() + skill_help);
	this->FBoard->Map->Obj.erase(this->FBoard->Map->Obj.begin() + skill_help);
	this->skill_help = NULL;
	 
}

void Superman::update(const float& dt)
{
	 
	this->elapsed2 = dt;
	this->skill2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float skill_dt = skill2 - skill1;
	float tem = this->getStats().speed_attack;
	
	
	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Supermana";
		this->attack(foe);
		this->elapsed1 = dt;
	}
	else if ((enemy == true && sub_dt < tem )||(type == OBJ_OBSTACLE && sub_dt < 5) )
	{
		
	} 
	else if (type == OBJ_OBSTACLE && sub_dt > 5)
	{
		this->skill();
		this->skill1 = dt;
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
	obstacle = false;
	type = OBJ_NONE;
	 
}
