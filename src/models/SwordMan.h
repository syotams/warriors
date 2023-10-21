#pragma once
#ifndef SWORDMAN_H_
#define SWORDMAN_H_

#include <iostream>
#include <map>
#include "raylib.h"
#include "../textures_container.h"
#include "../Constants.h"
#include "../views/IdleState.h"
#include "../views/WalkState.h"
#include "../views/WarriorStates.h"
#include "../views/AttackState.h"
#include "../Direction.h"
#include "../constrains/SimpleConstrain.h"
#include "../helpers/Log.h"
#include "Sprite.h"

class SwordMan : public Sprite
{
private:
    std::map<WarriorStates, State *> states;

protected:
    SwordMan(Vector2 position, Vector2 dimension, int maxSpeed);
    void setLookDirection(Vector2 dir);
    void setState(WarriorStates name);

    WarriorStates currentState;
    Direction lookDirection[2];

public:
    static SwordMan *make(TexturesContainer *container, Vector2 position);
    State *getState();
    void addState(WarriorStates name, State *state);
    WarriorStates getKnightState();
    virtual void move();
    void draw();
    void attack();
    void walk();
    void idle();
    ~SwordMan();
};

#endif // SWORDMAN_H_