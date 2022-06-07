#include "Obstacle.h"
#include "Board.h"
Obstacle::Obstacle(float pos_x, float pos_y, Board* FBoard)
	:Object(FBoard)
{
	this->setCoordinates(pos_x, pos_y);
	this->type = OBJ_OBSTACLE;
	this->foe = NULL; 
	this->isDestroyed = false;
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(const float& dt)
{
	if (this->type == OBJ_BOMB)
	{
		for (int i = 0; i < FBoard->Objects.size(); i++)
		{ 
			if (((this->SomethingIsNear(FBoard->Objects[i], 70)) == true) && (this->Team == FBoard->Objects[i]->Team))
			{
				this->foe = FBoard->Objects[i];
				this->foe->changeHP(15);
				this->isDestroyed = true;
			}
		}
	}
}
 
 