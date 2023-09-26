#include "AttackState.h"

AttackState::AttackState(Texture2D *rightSidedTextures, Texture2D *leftSidedTextures) : State(0, 10), rightSidedTextures(rightSidedTextures), leftSidedTextures(leftSidedTextures)
{
    setFramesPerSecond(16);
}

AttackState *AttackState::make()
{
    std::array<Texture2D *, 2> _textures = load_lr_animated_images(10, "resources/knight/png/Attack (%d).png");
    return new AttackState(_textures[0], _textures[1]);
}

void AttackState::draw(Vector2 position, Direction *direction)
{
    if (Direction::Right == direction[0])
    {
        DrawTexture(rightSidedTextures[getCurrentFrame()], position.x, position.y, WHITE);
    }
    else if (Direction::Left == direction[0])
    {
        DrawTexture(leftSidedTextures[getCurrentFrame()], position.x, position.y, WHITE);
    }
}

AttackState::~AttackState()
{
    for (int i = 0; i < 10; i++)
    {
        UnloadTexture(rightSidedTextures[i]);
        UnloadTexture(leftSidedTextures[i]);
    }
    delete[] rightSidedTextures;
    delete[] leftSidedTextures;
}
