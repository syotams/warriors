#pragma once
#ifndef ENEMY_H_
#define ENEMY_H_

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
#include "SwordMan.h"

class Enemy : public SwordMan
{
private:
    Enemy(Vector2 position, Vector2 dimension, int maxSpeed);

public:
    static Enemy *make(TexturesContainer *container, Vector2 position);
    void move();
    ~Enemy();
};

#endif // ENEMY_H_