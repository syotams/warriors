#include "WalkState.h"

WalkState::WalkState(Texture2D *rTextures, Texture2D *lTextures) : State(0, 10), rTextures(rTextures), lTextures(lTextures)
{
    setFramesPerSecond(16);
}

WalkState *WalkState::make(TexturesContainer *container)
{
    Texture2D *rTextures = textures_container_get_textures(container, TexturesNames::Knight_Run_Right);
    Texture2D *lTextures = textures_container_get_textures(container, TexturesNames::Knight_Run_Left);
    return new WalkState(rTextures, lTextures);
}

void WalkState::draw(Vector2 position, Direction *direction)
{
    switch (direction[0])
    {
    case Direction::Right:
    default:
        DrawTexture(rTextures[getCurrentFrame()], position.x, position.y, WHITE);
        break;

    case Direction::Left:
        DrawTexture(lTextures[getCurrentFrame()], position.x, position.y, WHITE);
        break;
    }
}

WalkState::~WalkState()
{
    log("WalkState::~WalkState() destruct all pointers array");
    delete[] rTextures;
    delete[] lTextures;
}
