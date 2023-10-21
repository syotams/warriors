#include "AttackState.h"

AttackState::AttackState(Texture2D *rTextures, Texture2D *lTextures) : State(0, 10), rTextures(rTextures), lTextures(lTextures)
{
    setFramesPerSecond(16);
}

AttackState *AttackState::make(TexturesContainer *container)
{
    Texture2D *rTextures = textures_container_get_textures(container, TexturesNames::Knight_Attack_Right);
    Texture2D *lTextures = textures_container_get_textures(container, TexturesNames::Knight_Attack_Left);
    return new AttackState(rTextures, lTextures);
}

void AttackState::draw(Vector2 position, Direction *direction)
{
    State::draw(position, direction);
    if (Direction::Right == direction[0])
    {
        DrawTexture(rTextures[getCurrentFrame()], position.x, position.y, WHITE);
    }
    else if (Direction::Left == direction[0])
    {
        DrawTexture(lTextures[getCurrentFrame()], position.x, position.y, WHITE);
    }
}

AttackState::~AttackState()
{
    log("AttackState::~AttackState() deconstruct all pointers array");
}
