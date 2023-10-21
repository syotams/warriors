#include "IdleState.h"

IdleState::IdleState(Texture2D *rTextures, Texture2D *lTextures) : State(0, 10), rTextures(rTextures), lTextures(lTextures)
{
    setFramesPerSecond(8);
}

IdleState *IdleState::make(TexturesContainer *container)
{
    Texture2D *rTextures = textures_container_get_textures(container, TexturesNames::Knight_Idle_Right);
    Texture2D *lTextures = textures_container_get_textures(container, TexturesNames::Knight_Idle_Left);
    return new IdleState(rTextures, lTextures);
}

void IdleState::draw(Vector2 position, Direction *direction)
{
    if (Direction::Right == direction[0])
    {
        DrawTextureRec(rTextures[getCurrentFrame()], {.x = 5, .y = 0, .width = 66, .height = 96}, position, WHITE);
        // DrawTextureV(rTextures[getCurrentFrame()], position, WHITE);
    }
    else if (Direction::Left == direction[0])
    {
        DrawTextureRec(lTextures[getCurrentFrame()], {.x = 5, .y = 0, .width = 66, .height = 96}, position, WHITE);
        // DrawTextureV(lTextures[getCurrentFrame()], position, WHITE);
    }
}

IdleState::~IdleState()
{
    log("IdleState::~IdleState() destruct pointers array");
}
