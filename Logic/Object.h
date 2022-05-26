#pragma once

class Board;
#include "Button.h"

struct Vector2f
{
	float Coordinate_X;
	float Coordinate_Y;

	Vector2f operator+(Vector2f other);

	Vector2f operator-(Vector2f other);

	Vector2f operator*(Vector2f other);

	Vector2f operator/(Vector2f other);

	Vector2f operator*(float scale);

	Vector2f operator/(float scale);
	  
	float magnitude();
};

struct defence
{
	float health;
	float armour;
	float speed;

};

class Object //Byt czyli wszyscy bohaterowie i zloczyncy
{
private:
	  
protected: 
	Vector2f cords;  
	defence attributes;
	 

public:
	//Atrybuty:
	Vector2f m_targetPosition; 
	Vector2f prev_cords;
	bool enemy;
	bool obstacle;
	bool Team;
	float elapsed1;
	float elapsed2;
	Object* foe; 
	Object* collision;
	Board* FBoard;
	int type;

//Konstruktor
	Object(Board* FBoard);

//Destruktor
	virtual ~Object();

 //Metody:	 
	void setCoordinates(float x, float y);

	Vector2f getCoordinates();

	defence getAttributes();
	
	void setAttributes(float health, float armour, float speed);

	void changeHP(float x);

	void changeSpeed(float x);

	virtual void update(const float& dt) = 0;

	bool SomethingIsNear(Object* object, float distance);

};

