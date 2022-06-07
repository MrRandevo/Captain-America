#include "Object.h"
#include "Board.h"
 
Vector2f Vector2f::operator+(Vector2f other)
{
	return Vector2f{ Coordinate_X + other.Coordinate_X,
					Coordinate_Y + other.Coordinate_Y };
}

Vector2f Vector2f::operator-(Vector2f other)
{
	return Vector2f{ Coordinate_X - other.Coordinate_X,
					Coordinate_Y - other.Coordinate_Y };
}

Vector2f Vector2f::operator*(Vector2f other)
{
	return Vector2f{ Coordinate_X * other.Coordinate_X,
					Coordinate_Y * other.Coordinate_Y };
}

Vector2f Vector2f::operator/(Vector2f other)
{
	return Vector2f{ Coordinate_X / other.Coordinate_X,
					Coordinate_Y / other.Coordinate_Y };
}

Vector2f Vector2f::operator*(float scale)
{
	return Vector2f{ Coordinate_X * scale, Coordinate_Y * scale };
}

Vector2f Vector2f::operator/(float scale)
{
	return Vector2f{ Coordinate_X / scale, Coordinate_Y / scale };
}

float Vector2f::magnitude()
{
	return std::sqrt(std::pow(Coordinate_X, 2) + std::pow(Coordinate_Y, 2));
}


Object::Object(Board* FBoard)
{
	this->FBoard = FBoard; 
	this->type = OBJ_NONE;
}
  
Object::~Object()
{
}
 
void Object::setCoordinates(float x, float y)
{
	cords.Coordinate_X = 25.0 + x * 50.0;
	cords.Coordinate_Y = 25.0 + y * 50.0;
}

Vector2f Object::getCoordinates()
{
	return cords;
}

defence Object::getAttributes()
{
	return this->attributes;
}

void Object::setAttributes(float health, float armour, float speed)
{
	this->attributes.armour = armour;
	this->attributes.health = health; 
	this->attributes.speed = speed;
}

void Object::changeHP(float x)
{ 
	this->attributes.health -= x;
	if (attributes.health < 0)
		attributes.health = 0; 
}

void Object::changeSpeed(float x)
{
	this->attributes.speed *= x;
}

bool Object::SomethingIsNear(Object* object, float distance)
{
	Vector2f temp = object->getCoordinates() - this->getCoordinates();

	if (temp.magnitude() < distance)
	{
		return true; 
	}
	return false;
}
 
 