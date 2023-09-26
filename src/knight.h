#include <iostream>
#include <map>
#include "raylib.h"
#include "Constants.h"
#include "IdleState.h"
#include "WalkState.h"
#include "KnightStates.h"
#include "Direction.h"

class Knight
{
private:
    std::map<KnightStates, State *> states;
    State *state;
    Vector2 position;
    int speed;
    Direction direction[2];

    Knight(Vector2 position);
    void setState(KnightStates name);

public:
    static Knight *make(Vector2 position);
    void addState(KnightStates name, State *state);
    void move();
    void draw();
    ~Knight();
};