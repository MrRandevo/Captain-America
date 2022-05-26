#include "Hero.h"

struct statistics;

//Konstruktor
Hero::Hero(Board* FBoard)
	:Object(FBoard)
{ 
	m_maxStraightMove = 300.f;
}

//Destruktor
Hero::~Hero()
{
}
void Hero::changeStats(float strength , float speed_attack )
{
	this->stats.strength = strength; 
	this->stats.speed_attack = speed_attack;
 
}

statistics Hero::getStats()
{
	return this->stats;
}
 
void Hero::move()
{
	if (MoveTowards(this->cords, this->m_targetPosition, this->prev_cords, this->getAttributes().speed))
	{ 
		do
		{
			m_targetPosition = RandomPointInRange(this->getCoordinates(), m_maxStraightMove);

		} while ((m_targetPosition.Coordinate_X < 10)
			|| (m_targetPosition.Coordinate_X > 980)
			|| (m_targetPosition.Coordinate_Y < 10)
			|| (m_targetPosition.Coordinate_Y > 580));
	}

}

void Hero::attack(Object* enemy)
{
	float armour = enemy->getAttributes().armour;
	float health = enemy->getAttributes().health;
	float strength = this->getStats().strength;

	float damage = strength * (1 - (armour / 100));
	std::cout << std::endl << "Damage: " << damage;
	enemy->changeHP(damage);
	std::cout << std::endl << "Zycie: " << enemy->getAttributes().health;
}

bool Hero::MoveTowards(Vector2f& originPosition, Vector2f targetPosition, Vector2f &prev_cords, float Distance)
{
	Vector2f dif = targetPosition - originPosition;
	float mag = dif.magnitude();
	if (mag <= Distance || mag == 0)
	{
		originPosition = targetPosition;
		return true;
	}
	prev_cords = originPosition;
	originPosition = dif / mag * Distance + originPosition;
	return false;
}

Vector2f Hero::RandomPointInRange(Vector2f origin, float range)
{
	float r = range * std::sqrt(randomFrom0To1());
	float alpha = randomFrom0To1() * 2 * 3.14;

	return Vector2f{ origin.Coordinate_X + r * std::cos(alpha),
					origin.Coordinate_Y + r * std::sin(alpha) };
}

float Hero::randomFrom0To1()
{
	return (((double)rand() / (RAND_MAX)) + 1);
}

 