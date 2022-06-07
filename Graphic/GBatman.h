#pragma once
#include "GObject.h"
#include "Batman.h"

class GBatman :
    public GObject
{
private:
     
    sf::Texture bomb_texture;
    sf::Sprite bomb_sprite;
protected: 
public:
    GBatman(Object* object );

    ~GBatman();
     
    void draw(sf::RenderTarget* target);

    void update(const float& dt);
 
};

