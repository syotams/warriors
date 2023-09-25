#include "simple_constrain.h"

SimpleConstrain::~SimpleConstrain()
{
    std::cout << "*** in SimpleConstrain::~SimpleConstrain" << std::endl;
}

void SimpleConstrain::apply()
{
    int x = 0, y = 0;
    if (IsKeyDown(KEY_RIGHT))
    {
        x = 1;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        x = -1;
    }
    else if (IsKeyDown(KEY_UP))
    {
        y = -1;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        y = 1;
    }
    player->moveBy(x, y);
}