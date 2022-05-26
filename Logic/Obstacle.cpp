#include "Obstacle.h"

Obstacle::Obstacle(float pos_x, float pos_y, Board* FBoard)
	:Object(FBoard)
{
	this->isDestroyed = false;
	this->setCoordinates(pos_x, pos_y);
	 
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(const float& dt)
{

}
 
 