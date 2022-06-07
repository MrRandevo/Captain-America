#pragma once

class Board;
#include "Button.h"

enum Objects_types { OBJ_NONE = 0, OBJ_WATER, OBJ_HEAL, OBJ_OBSTACLE, OBJ_BOMB };

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
	defence attributes; 
protected: 
	Vector2f cords;  

public:
//Atrybuty: 
	//Czy obok jest wrog?
	bool enemy;
	//Czy przeszkoda jest obok
	bool obstacle;
	//Ktora druzyna
	bool Team;
	//Rodzaj przeszkody
	short unsigned type;
	// 
	int skill_help;

	Object* foe;  
	Board* FBoard; 

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

