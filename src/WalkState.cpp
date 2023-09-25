#include "WalkState.h"

WalkState::WalkState(Texture2D *textures, Texture2D *leftSideTextures) : State(0, 10), textures(textures), leftSideTextures(leftSideTextures)
{
    setFramesPerSecond(16);
}

WalkState *WalkState::make()
{
    Texture2D *textures = new Texture2D[10];
    Texture2D *leftSideTextures = new Texture2D[10];
    for (int i = 0; i < 10; i++)
    {
        char file[100];
        snprintf(file, 100, "resources/knight/png/Run (%d).png", i + 1);

        Image image = LoadImage(file);
        textures[i] = LoadTextureFromImage(image); // 587x707
        ImageFlipHorizontal(&image);
        leftSideTextures[i] = LoadTextureFromImage(image);
        UnloadImage(image);

        if (textures[i].height < textures[i].width)
        {
            textures[i].height = TEXTURE_SIZE * textures[i].height / textures[i].width;
            textures[i].width = TEXTURE_SIZE;
        }
        else
        {
            textures[i].width = TEXTURE_SIZE * textures[i].width / textures[i].height;
            textures[i].height = TEXTURE_SIZE;
        }
        leftSideTextures[i].width = textures[i].width;
        leftSideTextures[i].height = textures[i].height;
    }
    return new WalkState(textures, leftSideTextures);
}

void WalkState::draw(Vector2 position, int direction)
{
    if (direction == 1)
    {
        DrawTexture(textures[getCurrentFrame()], position.x, position.y, WHITE);
    }
    else
    {
        DrawTexture(leftSideTextures[getCurrentFrame()], position.x, position.y, WHITE);
    }
}

WalkState::~WalkState()
{
    for (int i = 0; i < 10; i++)
    {
        UnloadTexture(textures[i]);
        UnloadTexture(leftSideTextures[i]);
    }
    delete[] textures;
    delete[] leftSideTextures;
}
