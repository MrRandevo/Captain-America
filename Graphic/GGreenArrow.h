#pragma once
#include "GObject.h"
#include "GreenArrow.h"

class GGreenArrow :
    public GObject
{
private:

protected:

public:
    GGreenArrow(Object* object );

    ~GGreenArrow();

    void draw(sf::RenderTarget* target);

    void update(const float& dt);
};

