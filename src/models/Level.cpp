#include "Level.h"

void Level::loadBackgroundImages()
{
    char file_name[] = "resources/forest-1/%d.png";
    for (int i = 0; i < TOTAL_IMAGES; i++)
    {
        char file[100];
        snprintf(file, 100, file_name, i);
        backgrounds[i] = LoadTexture(file);
        backgrounds[i].width = backgrounds[i].width * screenHeight / 1392 / 1.3;
        backgrounds[i].height = backgrounds[i].height * screenHeight / 1392 / 1.3;
        printf("*** Loaded %s (%d, %d)\n", file, backgrounds[i].width, backgrounds[i].height);
        positions[i] = 0;
    }
}

Level *Level::make(TexturesContainer *container, int screenWidth, int screenHeight)
{
    Level *level = new Level(screenWidth, screenHeight);
    level->loadBackgroundImages();
    // Vector2 knightPosition({.x = (float)(screenWidth / 2), .y = (float)(screenHeight / 2)});
    // level->cpuPlayer = Knight::make(container, knightPosition);
    // level->cpuPlayer->addConstrain(new );
    return level;
}

void Level::move()
{
    for (int i = 0; i < TOTAL_IMAGES; i++)
    {
        positions[i] -= i * 0.5;
        if (positions[i] < backgrounds[i].width)
        {
            positions[i] = 0;
        }
    }
    // cpuPlayer->move();
}

void Level::draw()
{
    ClearBackground(BACKGROUND_LIGHT_GREEN);
    DrawTexture(backgrounds[5], positions[5], 0, WHITE);
    DrawTexture(backgrounds[4], positions[4], 0, WHITE);
    DrawTexture(backgrounds[3], positions[3], 0, WHITE);
    DrawTexture(backgrounds[2], positions[2], backgrounds[2].height, WHITE);
    DrawTexture(backgrounds[1], positions[1], screenHeight - backgrounds[1].height, WHITE);
    DrawTexture(backgrounds[0], positions[0], screenHeight - backgrounds[0].height, WHITE);
    // cpuPlayer->draw();
}

Level::~Level()
{
    log("Level::~Level() destructing backgrounds of level I");
    for (Texture2D background : backgrounds)
    {
        UnloadTexture(background);
    }
    // delete cpuPlayer;
}
