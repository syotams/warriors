#include <iostream>
#include <map>
#include "raylib.h"
#include "Constants.h"
#include "IdleState.h"
#include "WalkState.h"
#include "KnightStates.h"
#include "AttackState.h"
#include "Direction.h"
#include "constrains/SimpleConstrain.h"
#include "Sprite.h"

class Knight : Sprite
{
private:
    std::map<KnightStates, State *> states;
    KnightStates currentState;
    Vector2 position;
    Direction lookDirection[2];
    Direction walkDirection[2];
    std::vector<Constrain *> consrains;
    int speed;

    Knight(Vector2 position, Vector2 dimension, int max_size);
    void setState(KnightStates name);
    State *getState();

public:
    static Knight *make(Vector2 position);
    void addState(KnightStates name, State *state);
    void move();
    void draw();
    ~Knight();
};