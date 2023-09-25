#include <stdio.h>
#include "raylib.h"
#include "knight.h"
#include "constants.h"

int SCREEN_WIDTH = 0;
int SCREEN_HEIGHT = 0;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(0, 0, "Example 3");
    SCREEN_WIDTH = GetScreenWidth() / 2;
    SCREEN_HEIGHT = GetScreenHeight() / 2;
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
                      //--------------------------------------------------------------------------------------

    Knight *knight = Knight::make(SCREEN_WIDTH, SCREEN_HEIGHT);

    int currentFrame = 0;
    int framesCounter = 0;
    int framesPerSecond = 8;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        knight->move();

        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        knight->draw();

        EndDrawing();
    }

    // De-Initialization
    delete knight;
    //--------------------------------------------------------------------------------------

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}