#include <stdio.h>
#include "raylib.h"
#include "State.h"
#include "Constants.h"

class WalkState : public State
{
private:
    Texture2D *textures;
    Texture2D *leftSideTextures;

public:
    WalkState(Texture2D *textures, Texture2D *leftSideTextures);
    ~WalkState();
    static WalkState *make();
    void draw(Vector2 position, int direction);
};