#include <iostream>
#include <map>
#include "raylib.h"
#include "Constants.h"
#include "IdleState.h"
#include "WalkState.h"

class Knight
{
private:
    std::map<std::string, State *> states;
    State *state;
    Vector2 position;
    int speed;
    int direction;

    Knight(Vector2 position);
    void setState(std::string name);

public:
    static Knight *make(Vector2 position);
    void addState(const std::string name, State *state);
    void move();
    void draw();
    ~Knight();
};