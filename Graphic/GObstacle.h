#pragma once
#include "GObject.h"

class GObstacle :
    public GObject
{
private:
     
   

protected:


public:
    GObstacle(Object* object,sf::Texture *texture);

    ~GObstacle();
     
    void draw(sf::RenderTarget* target) ;
};

