#include "Knight.h"

Knight::Knight(Vector2 position, Vector2 dimension, int maxSpeed) : Sprite(position, dimension, maxSpeed)
{
    setSpeed(0);
    lookDirection[0] = Direction::Right;
}

Knight *Knight::make(TexturesContainer *container, Vector2 position)
{
    Knight *knight = new Knight(position, {.x = TEXTURE_SIZE * 0.75, .y = TEXTURE_SIZE}, KNIGHT_MAX_SPEED);
    knight->addState(KnightStates::Idle, IdleState::make(container));
    knight->addState(KnightStates::Walk, WalkState::make(container));
    knight->addState(KnightStates::Attack, AttackState::make(container));
    knight->setState(KnightStates::Idle);
    return knight;
}

void Knight::move()
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

    // Handle attack states (temporary)
    if (IsKeyDown(KEY_SPACE) || (currentState == KnightStates::Attack && !getState()->isCompleted()))
    {
        attack();
    }
    else if (walkDirection.x != 0 || walkDirection.y != 0)
    {
        setState(KnightStates::Walk);
        setSpeed(getMaxSpeed());
    }
    else
    {
        idle();
    }

    int speed = getSpeed();
    position.x += (int)walkDirection.x * speed;
    position.y += (int)walkDirection.y * speed;

    getState()->move();
}

void Knight::attack()
{
    setState(KnightStates::Attack);
    setSpeed(0);
}

void Knight::idle()
{
    setState(KnightStates::Idle);
    setSpeed(0);
}

void Knight::draw()
{
    getState()->draw(position, lookDirection);
    Rectangle rect = rectacngle();
    DrawRectangleLines(position.x, position.y, rect.width, rect.height, BLACK);
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

KnightStates Knight::getKnightState()
{
    return currentState;
}

void Knight::setLookDirection(Vector2 direction)
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

Knight::~Knight()
{
    log("Knight::~Knight() destructing player states and constrains");
    for (std::map<KnightStates, State *>::iterator itr = states.begin(); itr != states.end(); itr++)
    {
        delete (itr->second);
    }
    states.clear();
}