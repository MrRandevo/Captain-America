#include "AStar.h"
#include "Board.h" 
#include "TileMap.h"

inline bool operator<(const Node& lhs, const Node& rhs)
{
    return lhs.fCost < rhs.fCost;
}

AStar::AStar(Board* FBoard)
{ 
    this->FBoard = FBoard;
}

AStar::~AStar()
{
}
 
bool AStar::isValid(int x, int y)
{ 
    int id = x + y * 20;

    if ((FBoard->Map->temp[id] == 0) || (FBoard->Map->temp[id] == 2) || (FBoard->Map->temp[id] == 6))
    { 
        if (x < 0 || y < 0 || x >= X_TILES || y >= Y_TILES)
        {
            return false;
        }
        return true;
    }
    return false;
}

bool AStar::isDestination(int x, int y, Node dest)
{
    if (x == dest.x && y == dest.y) {
        return true;
    }
    return false;
}

double AStar::calculateH(int x, int y, Node dest)
{
    double H = (sqrt((x - dest.x) * (x - dest.x)
        + (y - dest.y) * (y - dest.y)));
    return H;
}

std::vector<Node> AStar::aStar(Node player, Node dest)
{
    std::vector<Node> empty;
    if (isValid(dest.x, dest.y) == false) 
    {
       // std::cout << "Przeszkoda" << std::endl;
        return empty; 
    }
    if (isDestination(player.x, player.y, dest)) 
    {
       // std::cout << "Cel to gracz" << std::endl;
        return empty; 
    }
    bool closedList[X_TILES][Y_TILES];
     
    std::array<std::array < Node, (Y_TILES)>, (X_TILES)> allMap;
    for (int x = 0; x < (X_TILES); x++) 
    {
        for (int y = 0; y < (Y_TILES); y++) 
        {
            allMap[x][y].fCost = FLT_MAX;
            allMap[x][y].gCost = FLT_MAX;
            allMap[x][y].hCost = FLT_MAX;
            allMap[x][y].parentX = -1;
            allMap[x][y].parentY = -1;
            allMap[x][y].x = x;
            allMap[x][y].y = y;
            closedList[x][y] = false;
        }
    }
     
    int x = player.x;
    int y = player.y;
    allMap[x][y].fCost = 0.0;
    allMap[x][y].gCost = 0.0;
    allMap[x][y].hCost = 0.0;
    allMap[x][y].parentX = x;
    allMap[x][y].parentY = y;

    std::vector<Node> openList;
    openList.emplace_back(allMap[x][y]);
    bool destinationFound = false;

    while (!openList.empty() && openList.size() < (X_TILES * Y_TILES)) 
    {

        Node node;
        do {
            float temp = FLT_MAX;
            std::vector<Node>::iterator itNode;

            for (std::vector<Node>::iterator it = openList.begin(); it != openList.end(); it = next(it))
            {
                Node n = *it;
                if (n.fCost < temp) {
                    temp = n.fCost;
                    itNode = it;
                }
            }
            node = *itNode;
            openList.erase(itNode);

        } while (isValid(node.x, node.y) == false);

        x = node.x;
        y = node.y;
        closedList[x][y] = true;
         
        for (int newX = -1; newX <= 1; newX++) {
            for (int newY = -1; newY <= 1; newY++) {
                double gNew, hNew, fNew;
                if (isValid(x + newX, y + newY)) {
                    if (isDestination(x + newX, y + newY, dest))
                    { 
                        allMap[x + newX][y + newY].parentX = x;
                        allMap[x + newX][y + newY].parentY = y;
                        destinationFound = true;
                        return makePath(allMap, dest);
                    }
                    else if (closedList[x + newX][y + newY] == false)
                    {
                        gNew = node.gCost + 1.0;
                        hNew = calculateH(x + newX, y + newY, dest);
                        fNew = gNew + hNew; 
                        if (allMap[x + newX][y + newY].fCost == FLT_MAX ||
                            allMap[x + newX][y + newY].fCost > fNew)
                        { 
                            allMap[x + newX][y + newY].fCost = fNew;
                            allMap[x + newX][y + newY].gCost = gNew;
                            allMap[x + newX][y + newY].hCost = hNew;
                            allMap[x + newX][y + newY].parentX = x;
                            allMap[x + newX][y + newY].parentY = y;
                            openList.emplace_back(allMap[x + newX][y + newY]);
                        }
                    }
                }
            }
        }
    }
    if (destinationFound == false) {
       // std::cout << "Destination not found" << std::endl;
        return empty;
    }
}

std::vector<Node> AStar::makePath(std::array<std::array<Node, Y_TILES>, X_TILES> map, Node dest)
{
    try {
       // std::cout << "Found a path" << std::endl;
        int x = dest.x;
        int y = dest.y;
        std::stack<Node> path;
        std::vector<Node> usablePath;

        while (!(map[x][y].parentX == x && map[x][y].parentY == y)
            && map[x][y].x != -1 && map[x][y].y != -1)
        {
            path.push(map[x][y]);
            int tempX = map[x][y].parentX;
            int tempY = map[x][y].parentY;
            x = tempX;
            y = tempY;

        }
        path.push(map[x][y]);

        while (!path.empty()) {
            Node top = path.top();
            path.pop();
            usablePath.emplace_back(top);
        }
        return usablePath;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

 