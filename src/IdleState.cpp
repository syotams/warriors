#include "IdleState.h"

IdleState::IdleState(Texture2D *textures, Texture2D *leftSidedTextures) : State(0, 10), textures(textures), leftSidedTextures(leftSidedTextures)
{
    setFramesPerSecond(8);
}

IdleState *IdleState::make()
{
    std::array<Texture2D *, 2> _textures = load_lr_animated_images(10, "resources/knight/png/Idle (%d).png", TEXTURE_SIZE);
    return new IdleState(_textures[0], _textures[1]);
}

void IdleState::draw(Vector2 position, Direction *direction)
{
    if (Direction::Right == direction[0])
    {
        DrawTexture(textures[getCurrentFrame()], position.x, position.y, WHITE);
    }
    else if (Direction::Left == direction[0])
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
