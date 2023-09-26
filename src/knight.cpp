#include "Knight.h"

Knight::Knight(Vector2 position) : position(position)
{
    speed = 0;
    walkDirection[0] = Direction::None;
    lookDirection[0] = Direction::Right;
}

Knight *Knight::make(Vector2 position)
{
    Knight *knight = new Knight(position);
    knight->addState(KnightStates::Idle, IdleState::make());
    knight->addState(KnightStates::Walk, WalkState::make());
    knight->addState(KnightStates::Attack, AttackState::make());
    knight->setState(KnightStates::Idle);
    return knight;
}

void Knight::move()
{
    int x = 0, y = 0;
    if (IsKeyDown(KEY_RIGHT))
    {
        x = 1;
        walkDirection[0] = Direction::Right;
        lookDirection[0] = Direction::Right;
        walkDirection[1] = Direction::None;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        x = -1;
        walkDirection[0] = Direction::Left;
        lookDirection[0] = Direction::Left;
        walkDirection[1] = Direction::None;
    }
    if (IsKeyDown(KEY_UP))
    {
        y = -1;
        walkDirection[1] = Direction::Up;
        walkDirection[0] = Direction::None;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        y = 1;
        walkDirection[1] = Direction::Down;
        walkDirection[0] = Direction::None;
    }

    // Handle attack states (temporary)
    if (IsKeyDown(KEY_SPACE) || (currentState == KnightStates::Attack && getState()->getCurrentFrame() < 9))
    {
        setState(KnightStates::Attack);
    }
    else if (x != 0 || y != 0)
    {
        setState(KnightStates::Walk);
        speed = KNIGHT_MAX_SPEED;
    }
    else
    {
        setState(KnightStates::Idle);
        speed = 0;
    }

    stateTimer = stateTimer > 0 ? stateTimer - 1 : 0;
    position.x += (int)walkDirection[0] * speed;
    position.y += (int)walkDirection[1] * speed;
    getState()->move();
}

void Knight::draw()
{
    getState()->draw(position, lookDirection);
}

void Knight::addState(KnightStates name, State *state)
{
    this->states.insert(std::make_pair(name, state));
}

State *Knight::getState()
{
    return states.find(currentState)->second;
}

void Knight::setState(KnightStates name)
{
    std::map<KnightStates, State *>::iterator itr = states.find(name);
    if (itr != states.end())
    {
        this->currentState = name;
    }
}

Knight::~Knight()
{
    for (std::map<KnightStates, State *>::iterator itr = states.begin(); itr != states.end(); itr++)
    {
        delete (itr->second);
    }
    states.clear();
}