#include "dog_chase_constrain.h"

DogChaseConstrain::~DogChaseConstrain()
{
    std::cout << "*** in DogChaseConstrain::~DogChaseConstrain" << std::endl;
}

void DogChaseConstrain::apply()
{
    Vector2 position = chaser->getPosition();
    Vector2 chasedPosition = chased->getPosition();
    float yDiff = chasedPosition.y - position.y;
    float xDiff = chasedPosition.x - position.x;

    double distance = sqrt(yDiff * yDiff + xDiff * xDiff);

    if (distance > 0)
    {
        chaser->moveBy(xDiff / distance, yDiff / distance);
    }
}