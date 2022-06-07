#pragma once
 
class Board;
class TileMap;

#include <iostream>
#include <vector>
#include <array>
 
#define X_TILES 20
#define Y_TILES 12

struct Node
{
    int y;
    int x;
    int parentX;
    int parentY;
    float gCost;
    float hCost;
    float fCost;
};

inline bool operator <(const Node& lhs, const Node& rhs);

class AStar
{
public:
    //Atrybuty: 
    Board* FBoard;
    Node player;
    Node dest;

    //Konstruktor
    AStar(Board* FBoard);
    //Destruktor
    ~AStar();

    bool isValid(int x, int y);

    bool isDestination(int x, int y, Node dest);

    double calculateH(int x, int y, Node dest);

    std::vector <Node> aStar(Node player, Node dest);

    std::vector<Node> makePath(std::array<std::array<Node, Y_TILES>, X_TILES> map, Node dest);
};