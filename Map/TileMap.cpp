#include "TileMap.h"
#include "Board.h"
#include "Obstacle.h"

TileMap::TileMap(Board* FBoard)
{
    this->FBoard = FBoard;
    this->initTextures(); 
    this->initObjects();
}

TileMap::~TileMap()
{
    counter = NULL;
    delete counter;

    Obj.clear();
    Gobj.clear();

    auto it = this->Textures.begin();
    for (it = Textures.begin(); it != this->Textures.end(); ++it)
    {
        delete it->second;
    }

    for (auto& x : this->map)
    {
        x.clear();
    } 
    map.clear(); 
}

void TileMap::render(sf::RenderTarget* target)
{
    for (auto& x : this->map)
    { 
        for (auto& y : x)
        {
            target->draw(y); 
        }
    }

    for (int i = 0; i < Gobj.size(); i++)
        Gobj[i]->draw(target);
}

void TileMap::initTextures()
{
    this->Textures["Grass"] = new sf::Texture();
    Textures["Grass"]->loadFromFile("Sprite\\grass.png");

    this->Textures["Rock"] = new sf::Texture();
    Textures["Rock"]->loadFromFile("Sprite\\rock.png");

    this->Textures["Water"] = new sf::Texture();
    Textures["Water"]->loadFromFile("Sprite\\water.png");

    this->Textures["GreenTree"] = new sf::Texture();
    Textures["GreenTree"]->loadFromFile("Sprite\\GreenTree.png");

    this->Textures["BrownTree"] = new sf::Texture();
    Textures["BrownTree"]->loadFromFile("Sprite\\BrownTree.png");

    this->Textures["BlueTree"] = new sf::Texture();
    Textures["BlueTree"]->loadFromFile("Sprite\\BlueTree.png");

}

void TileMap::initObjects()
{
    this->maxSize_x = 20;
    this->maxSize_y = 12;
    this->gridSize = 50;

    counter = new int[maxSize_x * maxSize_y]
    {
     0, 0, 0, 0, 0, 0, 4, 0, 0, 5, 0, 0, 0, 1, 0, 0, 3, 2, 0, 0, 
     0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2, 2, 0, 0, 
     0, 0, 1, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0,
     0, 0, 1, 2, 2, 2, 1, 2, 2, 0, 5, 3, 0, 0, 0, 3, 0, 0, 0, 0, 
     0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 2, 5, 5, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
     0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 
     0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0,
    };

    int count = 0;
    for (int x = 0; x < maxSize_x; x++)
    {
        this->map.push_back(std::vector<sf::RectangleShape>());

        for (int y = 0; y < maxSize_y; y++)
        {
            this->map[x].push_back(sf::RectangleShape());

            this->map[x][y].setPosition(sf::Vector2f(gridSize * x, gridSize * y));
            this->map[x][y].setSize(sf::Vector2f(50, 50));
            this->map[x][y].setTexture(Textures["Grass"]);

            switch (counter[20 * y + x])
            {
            case 0:
                break;
            case 1:
                Obj.push_back(new Obstacle((50 * x)+25, (50 * y) + 25, FBoard));
                Gobj.push_back(new GObstacle(Obj[count], Textures["Rock"]));
                count++;
                break;
            case 2:
                Obj.push_back(new Obstacle((50 * x) + 25, (50 * y) + 25, FBoard));
                Gobj.push_back(new GObstacle(Obj[count], Textures["Water"]));
                Obj[count]->type = 1; 
                count++;
                break;
            case 3:
                Obj.push_back(new Obstacle((50 * x) + 25, (50 * y) + 25, FBoard));
                Gobj.push_back(new GObstacle(Obj[count], Textures["GreenTree"]));
                count++;
                break;
            case 4:
                Obj.push_back(new Obstacle((50 * x) + 25, (50 * y) + 25, FBoard));
                Gobj.push_back(new GObstacle(Obj[count], Textures["BrownTree"]));
                count++;
                break;
            case 5:
                Obj.push_back(new Obstacle((50 * x) + 25, (50 * y) + 25, FBoard));
                Gobj.push_back(new GObstacle(Obj[count], Textures["BlueTree"]));
                count++;
                break;
            }
        }
    }
}

void TileMap::update(const float& dt)
{
    for (int i = 0; i < Obj.size(); i++)
    {
        for (int j = 0; j < FBoard->Objects.size(); j++)
        {
            if (Obj[i]->SomethingIsNear(FBoard->Objects[j], 36.0))
            { 
                if (Obj[i]->type == 0)
                {
                    FBoard->Objects[j]->collision = Obj[i];
                    FBoard->Objects[j]->obstacle = true;
                    FBoard->Objects[j]->type = 0;
                    break;
                }

                else
                { 
                    FBoard->Objects[j]->obstacle = true;
                    FBoard->Objects[j]->type = 1; 
                    break;

                }
            }
        }
        Obj[i]->update(dt);
        
    }
    
}
