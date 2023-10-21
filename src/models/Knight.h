#pragma once
#ifndef KNIGHT_H_
#define KNIGHT_H_

#include <iostream>
#include <map>
#include "raylib.h"
#include "../textures_container.h"
#include "../Constants.h"
#include "../views/IdleState.h"
#include "../views/WalkState.h"
#include "../views/KnightStates.h"
#include "../views/AttackState.h"
#include "../Direction.h"
#include "../constrains/SimpleConstrain.h"
#include "../helpers/Log.h"
#include "Sprite.h"

class Knight : public Sprite
{
private:
    std::map<KnightStates, State *> states;

protected:
    Knight(Vector2 position, Vector2 dimension, int maxSpeed);
    void setLookDirection(Vector2 dir);
    void setState(KnightStates name);

    KnightStates currentState;
    Direction lookDirection[2];

public:
    static Knight *make(TexturesContainer *container, Vector2 position);
    State *getState();
    void addState(KnightStates name, State *state);
    KnightStates getKnightState();
    virtual void move();
    void draw();
    void attack();
    void walk();
    void idle();
    ~Knight();
};

#endif // KNIGHT_H_