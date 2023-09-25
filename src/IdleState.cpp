#include "IdleState.h"

IdleState::IdleState(Texture2D *textures, Texture2D *leftSidedTextures) : State(0, 10), textures(textures), leftSidedTextures(leftSidedTextures)
{
    setFramesPerSecond(8);
}

IdleState *IdleState::make()
{
    Texture2D *textures = new Texture2D[10];
    Texture2D *leftSideTextures = new Texture2D[10];
    for (int i = 0; i < 10; i++)
    {
        char file[100];
        snprintf(file, 100, "resources/knight/png/Idle (%d).png", i + 1);
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
    IdleState *knight = new IdleState(textures, leftSideTextures);
    return knight;
}

void IdleState::draw(Vector2 position, int direction)
{
    if (direction > 0)
    {
        DrawTexture(textures[getCurrentFrame()], position.x, position.y, WHITE);
    }
    else
    {
        DrawTexture(leftSidedTextures[getCurrentFrame()], position.x, position.y, WHITE);
    }
}

IdleState::~IdleState()
{
    for (int i = 0; i < 10; i++)
    {
        UnloadTexture(textures[i]);
    }
    delete[] textures;
}
