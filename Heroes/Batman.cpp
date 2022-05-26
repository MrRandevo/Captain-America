#include "Batman.h"
#include "Board.h"

Batman::Batman(Board* FBoard)
	:Hero(FBoard)
{
	this->setAttributes(100, 40, 0.3);
	this->changeStats(40, 1);

	do
	{
		m_targetPosition = RandomPointInRange(this->getCoordinates(),
												m_maxStraightMove);

	} while ((m_targetPosition.Coordinate_X < 10)
		|| (m_targetPosition.Coordinate_X > 980)
		|| (m_targetPosition.Coordinate_Y < 10)
		|| (m_targetPosition.Coordinate_Y > 580));

	enemy = false;
	foe = NULL;
}

Batman::~Batman()
{
	
}

void Batman::skill()
{
	 
}

void Batman::update(const float& dt)
{
	this->elapsed2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float tem = this->getStats().speed_attack;
  
	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Batmana";
		this->attack(foe); 
		this->elapsed1 = dt;
	}
	else if (sub_dt < tem)
	{ 
		std::cout << std::endl << "War: " << sub_dt;
	}

	else if (obstacle == true && type == 0)
	{
		Vector2f temp = this->cords - this->prev_cords;
		temp = temp * 2;
		this->setCoordinates((cords.Coordinate_X - temp.Coordinate_X), (cords.Coordinate_Y - temp.Coordinate_Y));
		this->m_targetPosition = this->getCoordinates();

	}
	else
	{
		if (obstacle == true && type == 1)
		{
			this->changeSpeed(0.5);
			this->move();
			this->changeSpeed(2);

		}
		else
		{
			this->move(); 
		}
	}

	enemy = false;
	obstacle = false;
	type = 0;
}
