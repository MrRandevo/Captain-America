#include "Superman.h"
#include "Board.h" 
Superman::Superman(Board* FBoard)
	:Hero(FBoard)
{
	this->setAttributes(100, 50, 0.5);
	this->changeStats(20, 1 );
	this->prev_cords = { 0.0, 0.0 };
	do
	{
		m_targetPosition = RandomPointInRange(this->getCoordinates(),
											  m_maxStraightMove);

	} while ((m_targetPosition.Coordinate_X < 10)
		|| (m_targetPosition.Coordinate_X > 980)
		|| (m_targetPosition.Coordinate_Y < 10)
		|| (m_targetPosition.Coordinate_Y > 580));

	enemy = false;
	obstacle = false;
	collision = NULL;
	foe = NULL;
}

Superman::~Superman()
{
}

void Superman::skill()
{
	 
}

void Superman::update(const float& dt)
{
	
	this->elapsed2 = dt;
	float sub_dt = elapsed2 - elapsed1;
	float tem = this->getStats().speed_attack;
	
	/*for(int i=0;i<FBoard->Map->Obj.size();i++)
	{
		if(checkAround(FBoard->Map->Obj[i]))
		{
				this->FBoard->Map->Gobj.erase(this->FBoard->Map->Gobj.begin() + i);
				this->FBoard->Map->Obj.erase(this->FBoard->Map->Obj.begin() + i);
				break;
				std::cout << std::endl << "Kolizja";
		}
	} */
	
	if (enemy == true && sub_dt > tem)
	{
		std::cout << std::endl << "Atak Supermana";
		this->attack(foe);
		this->elapsed1 = dt;
	}
	else if (enemy == true && sub_dt < tem)
	{
		std::cout << std::endl << "War: " << sub_dt;
	}

	else if (obstacle == true && type == 0 )
	{
		Vector2f temp = this->cords - this->prev_cords;
		temp = temp * 2; 
		this->setCoordinates((cords.Coordinate_X - temp.Coordinate_X),(cords.Coordinate_Y - temp.Coordinate_Y)); 
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
