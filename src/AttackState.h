#include <stdio.h>
#include "raylib.h"
#include "State.h"
#include "Constants.h"
#include "ImageLoader.h"
#include "Direction.h"

class AttackState : public State
{
private:
    Texture2D *rightSidedTextures;
    Texture2D *leftSidedTextures;

public:
    AttackState(Texture2D *rightSidedTextures, Texture2D *leftSideTextures);
    ~AttackState();
    static AttackState *make();
    void draw(Vector2 position, Direction *direction);
};