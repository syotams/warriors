#include "Enemy.h"

Enemy *Enemy::make(TexturesContainer *container, Vector2 position)
{
    Enemy *swordMan = new Enemy(position, {.x = TEXTURE_SIZE * 0.75, .y = TEXTURE_SIZE}, KNIGHT_MAX_SPEED);
    swordMan->addState(WarriorStates::Idle, IdleState::make(container));
    swordMan->addState(WarriorStates::Walk, WalkState::make(container));
    swordMan->addState(WarriorStates::Attack, AttackState::make(container));
    swordMan->idle();
    return swordMan;
}

void Enemy::move()
{
    std::vector<Constrain *> constrains = getConstrains();
    if (constrains.size() > 0)
    {
        for (auto constrain : constrains)
        {
            constrain->apply();
        }
    }

    Vector2 walkDirection = getWalkDirection();
    setLookDirection(walkDirection);

    // Handle attack state on collision
    if (currentState == WarriorStates::Attack && !getState()->isCompleted())
    {
        attack();
    }
    else if (walkDirection.x != 0 || walkDirection.y != 0)
    {
        walk();
    }
    else
    {
        idle();
    }

    int speed = getSpeed();
    position.x += walkDirection.x * speed;
    position.y += walkDirection.y * speed;
}

Enemy::~Enemy()
{
    log("Enemy::~Enemy() destructing player states and constrains");
}