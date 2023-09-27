#include "SimpleConstrain.h"

SimpleConstrain::~SimpleConstrain()
{
    std::cout << "*** in SimpleConstrain::~SimpleConstrain" << std::endl;
}

void SimpleConstrain::apply()
{
    Direction walkDirection[2]{Direction::None, Direction::None};
    if (IsKeyDown(KEY_RIGHT))
    {
        walkDirection[0] = Direction::Right;
        walkDirection[1] = Direction::None;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        walkDirection[0] = Direction::Left;
        walkDirection[1] = Direction::None;
    }
    if (IsKeyDown(KEY_UP))
    {
        walkDirection[1] = Direction::Up;
        walkDirection[0] = Direction::None;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        walkDirection[1] = Direction::Down;
        walkDirection[0] = Direction::None;
    }
    player->moveBy(walkDirection[0], walkDirection[1]);
}