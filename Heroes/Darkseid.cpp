#include "Darkseid.h" 
#include "Board.h" 
Darkseid::Darkseid(Board* FBoard)
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

Darkseid::~Darkseid()
{
}

void Darkseid::skill()
{

}

void Darkseid::update(const float& dt)
{

	this->elapsed2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float tem = this->getStats().speed_attack;


	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Darkseida";
		this->attack(foe);
		this->elapsed1 = dt;
	}
	else if (enemy == true && sub_dt < tem)
	{

	} 
	else
	{
		if ( type == OBJ_WATER)
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
