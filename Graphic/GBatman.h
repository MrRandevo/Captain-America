#pragma once
#include "GObject.h"
#include "Batman.h"

class GBatman :
    public GObject
{
private:
    
protected:
    
public:
    GBatman(Object* object);

    ~GBatman();
     
    void draw(sf::RenderTarget* target);
 
};

