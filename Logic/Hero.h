#pragma once
#include "Object.h"
#include <string>
#include <ctime>
#include <ctime>
#include "AStar.h"
 
enum Hero_states { HRO_IDLE = 0, HRO_MOVE, HRO_ATTACK, HRO_SKILL };

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
public:
//Atrybuty: 
    std::vector <Node> path;
    AStar* Star;
    float elapsed1;
    float elapsed2;
    float skill1;
    float skill2;
    short unsigned HeroState;
//Konstruktor
    Hero(Board* FBoard);

//Destruktor
    ~Hero();
     
    void changeStats(float strength, float speed_attack);
     
    statistics getStats();

    virtual void update(const float& dt) = 0;

    virtual void skill() = 0;


    //Ruch
    void move(Vector2f& originPosition);

    //Znajdowanie sciezki
    void findPath();
    void randomCoords();
    //Atak
    void attack(Object* enemy);
     
};

