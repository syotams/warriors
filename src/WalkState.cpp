#include "WalkState.h"

WalkState::WalkState(Texture2D *rightSidedTextures, Texture2D *leftSidedTextures) : State(0, 10), rightSidedTextures(rightSidedTextures), leftSidedTextures(leftSidedTextures)
{
    setFramesPerSecond(16);
}

WalkState *WalkState::make()
{
    std::array<Texture2D *, 2> _textures = load_lr_animated_images(10, "resources/knight/png/Run (%d).png");
    return new WalkState(_textures[0], _textures[1]);
}

void WalkState::draw(Vector2 position, Direction *direction)
{
    switch (direction[0])
    {
    case Direction::Right:
    default:
        DrawTexture(rightSidedTextures[getCurrentFrame()], position.x, position.y, WHITE);
        break;

    case Direction::Left:
        DrawTexture(leftSidedTextures[getCurrentFrame()], position.x, position.y, WHITE);
        break;
    }
}

WalkState::~WalkState()
{
    for (int i = 0; i < 10; i++)
    {
        UnloadTexture(rightSidedTextures[i]);
        UnloadTexture(leftSidedTextures[i]);
    }
    delete[] rightSidedTextures;
    delete[] leftSidedTextures;
}
