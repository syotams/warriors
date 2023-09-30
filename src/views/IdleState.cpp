#include "IdleState.h"

IdleState::IdleState(Texture2D *textures, Texture2D *leftSidedTextures) : State(0, 10), textures(textures), leftSidedTextures(leftSidedTextures)
{
    setFramesPerSecond(8);
}

IdleState *IdleState::make()
{
    char file[] = "resources/knight/png/Idle (%d).png";
    std::array<Texture2D *, 2> _textures = load_lr_animated_images(10, file, TEXTURE_SIZE);
    return new IdleState(_textures[0], _textures[1]);
}

void IdleState::draw(Vector2 position, Direction *direction)
{
    if (Direction::Right == direction[0])
    {
        DrawTextureV(textures[getCurrentFrame()], position, WHITE);
    }
    else if (Direction::Left == direction[0])
    {
        DrawTextureV(leftSidedTextures[getCurrentFrame()], position, WHITE);
    }
}

IdleState::~IdleState()
{
    log("IdleState::~IdleState() deconstruct all pointers and images");
    for (int i = 0; i < 10; i++)
    {
        UnloadTexture(textures[i]);
    }
    delete[] textures;
}