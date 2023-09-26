#include <stdio.h>
#include "raylib.h"
#include "State.h"
#include "Constants.h"
#include "ImageLoader.h"
#include "Direction.h"

class WalkState : public State
{
private:
    Texture2D *rightSidedTextures;
    Texture2D *leftSidedTextures;

public:
    WalkState(Texture2D *rightSidedTextures, Texture2D *leftSideTextures);
    ~WalkState();
    static WalkState *make();
    void draw(Vector2 position, Direction *direction);
};