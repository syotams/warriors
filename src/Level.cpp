#include "Level.h"

void Level::loadImages()
{
    char file_name[] = "resources/forest-1/%d.png";
    for (int i = 0; i < 7; i++)
    {
        char file[100];
        snprintf(file, 100, file_name, i);
        backgrounds[i] = LoadTexture(file);
        backgrounds[i].width = backgrounds[i].width * screenHeight / 1392 / 1.3;
        backgrounds[i].height = backgrounds[i].height * screenHeight / 1392 / 1.3;
        printf("*** Loaded %s (%d, %d)\n", file, backgrounds[i].width, backgrounds[i].height);
    }
}

Level *Level::make(int screenWidth, int screenHeight)
{
    Level *level = new Level(screenWidth, screenHeight);
    level->loadImages();
    return level;
}

void Level::move()
{
}

void Level::draw()
{
    ClearBackground(BACKGROUND_LIGHT_GREEN);
    DrawTexture(backgrounds[5], 0, 0, WHITE);
    DrawTexture(backgrounds[4], 0, 0, WHITE);
    DrawTexture(backgrounds[3], 0, 0, WHITE);
    DrawTexture(backgrounds[2], 0, backgrounds[2].height, WHITE);
    DrawTexture(backgrounds[1], 0, screenHeight - backgrounds[1].height, WHITE);
    DrawTexture(backgrounds[0], 0, screenHeight - backgrounds[0].height, WHITE);
}

Level::~Level()
{
    for (Texture2D background : backgrounds)
    {
        UnloadTexture(background);
    }
}
