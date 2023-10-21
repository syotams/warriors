#include "SwordMan.h"

SwordMan::SwordMan(Vector2 position, Vector2 dimension, int maxSpeed) : Sprite(position, dimension, maxSpeed)
{
    setSpeed(0);
    lookDirection[0] = Direction::Right;
}

SwordMan *SwordMan::make(TexturesContainer *container, Vector2 position)
{
    SwordMan *swordMan = new SwordMan(position, {.x = TEXTURE_SIZE * 0.75, .y = TEXTURE_SIZE}, KNIGHT_MAX_SPEED);
    swordMan->addState(WarriorStates::Idle, IdleState::make(container));
    swordMan->addState(WarriorStates::Walk, WalkState::make(container));
    swordMan->addState(WarriorStates::Attack, AttackState::make(container));
    swordMan->idle();
    return swordMan;
}

void SwordMan::move()
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
    if (IsKeyDown(KEY_SPACE) || (currentState == WarriorStates::Attack && !getState()->isCompleted()))
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
    position.x += (int)walkDirection.x * speed;
    position.y += (int)walkDirection.y * speed;
}

void SwordMan::attack()
{
    if (currentState != WarriorStates::Attack)
    {
        getState()->reset();
    }
    setState(WarriorStates::Attack);
    setSpeed(0);
}

void SwordMan::walk()
{
    if (currentState != WarriorStates::Walk)
    {
        getState()->reset();
    }
    setState(WarriorStates::Walk);
    setSpeed(getMaxSpeed());
}

void SwordMan::idle()
{
    if (currentState != WarriorStates::Idle)
    {
        getState()->reset();
    }
    setState(WarriorStates::Idle);
    setSpeed(0);
}

void SwordMan::draw()
{
    getState()->draw(position, lookDirection);
    Rectangle rect = rectacngle();
    DrawRectangleLines(position.x, position.y, rect.width, rect.height, BLACK);
}

void SwordMan::addState(WarriorStates name, State *state)
{
    this->states.insert(std::make_pair(name, state));
}

State *SwordMan::getState()
{
    return states.find(currentState)->second;
}

void SwordMan::setState(WarriorStates name)
{
    std::map<WarriorStates, State *>::iterator itr = states.find(name);
    if (itr != states.end())
    {
        this->currentState = name;
    }
}

void SwordMan::setLookDirection(Vector2 direction)
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

SwordMan::~SwordMan()
{
    log("SwordMan::~SwordMan() destructing player states and constrains");
    for (std::map<WarriorStates, State *>::iterator itr = states.begin(); itr != states.end(); itr++)
    {
        delete (itr->second);
    }
    states.clear();
}