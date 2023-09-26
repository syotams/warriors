#include "Knight.h"

Knight::Knight(Vector2 position) : position(position)
{
    speed = 2;
    direction[0] = Direction::Right;
}

Knight *Knight::make(Vector2 position)
{
    Knight *knight = new Knight(position);
    knight->addState(KnightStates::Idle, IdleState::make());
    knight->addState(KnightStates::Walk, WalkState::make());
    knight->setState(KnightStates::Idle);
    return knight;
}

void Knight::move()
{
    int x = 0, y = 0;
    if (IsKeyDown(KEY_RIGHT))
    {
        x = 1;
        direction[0] = Direction::Right;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        x = -1;
        direction[0] = Direction::Left;
    }
    else if (IsKeyDown(KEY_UP))
    {
        y = -1;
        direction[1] = Direction::Up;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        y = 1;
        direction[1] = Direction::Down;
    }
    if (x != 0 || y != 0)
    {
        setState(KnightStates::Walk);
    }
    else
    {
        setState(KnightStates::Idle);
    }
    position.x += x * speed;
    position.y += y * speed;
    state->move();
}

void Knight::draw()
{
    state->draw(position, direction);
}

void Knight::addState(KnightStates name, State *state)
{
    this->states.insert(std::make_pair(name, state));
}

void Knight::setState(KnightStates name)
{
    std::map<KnightStates, State *>::iterator itr = states.find(name);
    if (itr != states.end())
    {
        this->state = itr->second;
    }
}

Knight::~Knight()
{
    for (std::map<KnightStates, State *>::iterator itr = states.begin(); itr != states.end(); itr++)
    {
        delete (itr->second);
    }
    states.clear();
    delete state;
}