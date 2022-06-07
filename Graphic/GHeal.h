#pragma once
#include "GObject.h"
class GHeal :
    public GObject
{
private:

protected:

public:
    GHeal(Object* object, sf::Texture* texture);

    ~GHeal();

    void draw(sf::RenderTarget* target);
};

