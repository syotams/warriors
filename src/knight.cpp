#include "knight.h"

Knight::Knight(Texture2D *knight_idle, int screenWidth, int screenHeight) : knight_idle(knight_idle), screenWidth(screenWidth), screenHeight(screenHeight)
{
    currentFrame = 0;
    framesCounter = 0;
    framesPerSecond = 8;
}

Knight *Knight::make(const int screenWidth, const int screenHeight)
{
    Texture2D *knight_idle = new Texture2D[10];
    for (int i = 0; i < 10; i++)
    {
        char file[100];
        snprintf(file, 100, "resources/knight/png/Idle (%d).png", i + 1);
        knight_idle[i] = LoadTexture(file); // 587x707
        if (knight_idle[i].height < knight_idle[i].width)
        {
            knight_idle[i].height = TEXTURE_SIZE * knight_idle[i].height / knight_idle[i].width;
            knight_idle[i].width = TEXTURE_SIZE;
        }
        else
        {
            knight_idle[i].width = TEXTURE_SIZE * knight_idle[i].width / knight_idle[i].height;
            knight_idle[i].height = TEXTURE_SIZE;
        }
    }
    Knight *knight = new Knight(knight_idle, screenWidth, screenHeight);
    return knight;
}

void Knight::move()
{
    if (framesCounter++ >= 60 / framesPerSecond)
    {
        framesCounter = 0;
        if (currentFrame++ >= 9)
            currentFrame = 0;
    }
}

void Knight::draw()
{
    DrawTexture(knight_idle[currentFrame], screenWidth / 2, screenHeight / 2, WHITE);
}

Knight::~Knight()
{
    for (int i = 0; i < 10; i++)
    {
        UnloadTexture(knight_idle[i]);
    }
    delete[] knight_idle;
}