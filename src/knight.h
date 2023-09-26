#include <iostream>
#include <map>
#include "raylib.h"
#include "Constants.h"
#include "IdleState.h"
#include "WalkState.h"
#include "KnightStates.h"
#include "AttackState.h"
#include "Direction.h"

class Knight
{
private:
    std::map<KnightStates, State *> states;
    KnightStates currentState;
    Vector2 position;
    int speed;
    int stateTimer;
    Direction lookDirection[2];
    Direction walkDirection[2];

    Knight(Vector2 position);
    void setState(KnightStates name);
    State *getState();

public:
    static Knight *make(Vector2 position);
    void addState(KnightStates name, State *state);
    void move();
    void draw();
    ~Knight();
};