#include "Enemy.h"

Enemy::Enemy(Vector2 position, Vector2 dimension, int maxSpeed) : Sprite(position, dimension, maxSpeed)
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

void Enemy::draw()
{
    getState()->draw(position, lookDirection);
    Rectangle rect = rectacngle();
    DrawRectangleLines(position.x, position.y, rect.width, rect.height, BLACK);
}

void Enemy::addState(KnightStates name, State *state)
{
    this->states.insert(std::make_pair(name, state));
}

void Enemy::attack()
{
    if (currentState != KnightStates::Attack)
    {
        getState()->reset();
    }
    setState(KnightStates::Attack);
    setSpeed(0);
}

void Enemy::walk()
{
    if (currentState != KnightStates::Walk)
    {
        getState()->reset();
    }
    setState(KnightStates::Walk);
    setSpeed(getMaxSpeed());
}

void Enemy::idle()
{
    if (currentState != KnightStates::Idle)
    {
        getState()->reset();
    }
    setState(KnightStates::Idle);
    setSpeed(0);
}

State *Enemy::getState()
{
    return states.find(currentState)->second;
}

void Enemy::setState(KnightStates name)
{
    std::map<KnightStates, State *>::iterator itr = states.find(name);
    if (itr != states.end())
    {
        this->currentState = name;
    }
}

KnightStates Enemy::getKnightState()
{
    return currentState;
}

void Enemy::setLookDirection(Vector2 direction)
{
    if (direction.x != 0)
    {
        lookDirection[0] = direction.x > 0 ? Direction::Right : Direction::Left;
    }
    if (direction.y != 0)
    {
        lookDirection[1] = direction.y > 0 ? Direction::Down : Direction::Up;
    }
}

Enemy::~Enemy()
{
    log("Enemy::~Enemy() destructing player states and constrains");
    for (std::map<KnightStates, State *>::iterator itr = states.begin(); itr != states.end(); itr++)
    {
        delete (itr->second);
    }
    states.clear();
}