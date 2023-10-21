#pragma once
#ifndef ENEMY_H_
#define ENEMY_H_

#include "SwordMan.h"

class Enemy : public SwordMan
{
private:
    Enemy(Vector2 position, Vector2 dimension, int maxSpeed) : SwordMan(position, dimension, maxSpeed){};

public:
    static Enemy *make(TexturesContainer *container, Vector2 position);
    void move() override;
    ~Enemy();
};

#endif // ENEMY_H_