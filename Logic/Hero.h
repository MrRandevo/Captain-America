#pragma once
#include "Object.h"
#include <string>
#include <ctime>
#include <ctime>

struct statistics
{
    float strength; 
    float speed_attack; 
}; 

class Hero :
    public Object 
{
private:
 //Atrybuty:
    statistics stats;

protected: 
//Atrybuty:
    float m_maxStraightMove; 
public:
//Konstruktor
    Hero(Board* FBoard);

//Destruktor
    ~Hero();
     
    void changeStats(float strength, float speed_attack);
     
    statistics getStats();

    virtual void update(const float& dt) = 0;

    virtual void skill() = 0;


    //Ruch
    void move();

    //Atak
    void attack(Object* enemy);

    bool MoveTowards(Vector2f& originPosition, Vector2f targetPosition, Vector2f &prev_cords, float Distance);

    Vector2f RandomPointInRange(Vector2f origin, float range);

    float randomFrom0To1();
     

};

