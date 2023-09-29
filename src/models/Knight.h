#pragma once
#ifndef KNIGHT_H_
#define KNIGHT_H_

#include <iostream>
#include <map>
#include "raylib.h"
#include "../Constants.h"
#include "../views/IdleState.h"
#include "../views/WalkState.h"
#include "../views/KnightStates.h"
#include "../views/AttackState.h"
#include "../Direction.h"
#include "../constrains/SimpleConstrain.h"
#include "../helpers/Log.h"
#include "Sprite.h"

class Knight : Sprite
{
private:
    std::map<KnightStates, State *> states;
    KnightStates currentState;
    Direction lookDirection[2];
    std::vector<Constrain *> consrains;
    int speed;

    Knight(Vector2 position, Vector2 dimension, int max_size);
    void setState(KnightStates name);
    State *getState();
    void setLookDirection(Vector2 dir);

public:
    static Knight *make(Vector2 position);
    void addState(KnightStates name, State *state);
    void move();
    void draw();
    ~Knight();
};

#endif // KNIGHT_H_