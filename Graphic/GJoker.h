#pragma once
#include "GObject.h"
#include "Joker.h"
class GJoker :
    public GObject
{
private:
protected:

public:
    GJoker(Object* object);

    ~GJoker();

    void draw(sf::RenderTarget* target);

};

