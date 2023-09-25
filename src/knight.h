#include <stdio.h>
#include "raylib.h"
#include "constants.h"

class Knight
{
private:
    Texture2D *knight_idle;
    Vector2 position;
    int screenWidth;
    int screenHeight;
    int currentFrame;
    int framesCounter;
    int framesPerSecond;

    Knight(Texture2D *knight_idle, int screenWidth, int screenHeight);

public:
    static Knight *make(const int screenWidth, const int screenHeight);
    void move();
    void draw();
    ~Knight();
};