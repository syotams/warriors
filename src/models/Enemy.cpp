#include "Enemy.h"

Enemy::Enemy(Vector2 position, Vector2 dimension, int maxSpeed) : Knight(position, dimension, maxSpeed)
{
    setSpeed(0);
    lookDirection[0] = Direction::Right;
}

Enemy *Enemy::make(TexturesContainer *container, Vector2 position)
{
    Enemy *knight = new Enemy(position, {.x = TEXTURE_SIZE * 0.75, .y = TEXTURE_SIZE}, KNIGHT_MAX_SPEED);
    knight->addState(KnightStates::Idle, IdleState::make(container));
    knight->addState(KnightStates::Walk, WalkState::make(container));
    knight->addState(KnightStates::Attack, AttackState::make(container));
    knight->idle();
    return knight;
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
    if (currentState == KnightStates::Attack && !getState()->isCompleted())
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

    getState()->move();
}

Enemy::~Enemy()
{
    log("Enemy::~Enemy() destructing player states and constrains");
}