#include "Heal.h"

Heal::Heal(float pos_x, float pos_y, Board* FBoard) :
	Object(FBoard)
{
	this->setCoordinates(pos_x, pos_y);
	this->heal = 35.0;
	this->type = OBJ_HEAL;
	this->foe = NULL;
}

Heal::~Heal()
{
}

void Heal::increaseHealth(Object* object)
{
	object->changeHP(-heal);
}

void Heal::update(const float& dt)
{
	if (foe != NULL)
	{
		increaseHealth(foe);
	}
	foe = NULL;
}
