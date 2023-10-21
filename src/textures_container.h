#pragma once
#ifndef TEXTURESCONTAINER_H_
#define TEXTURESCONTAINER_H_

#include <map>
#include "raylib.h"
#include "TexturesNames.h"
#include "helpers/Log.h"

typedef struct
{
    std::map<TexturesNames, Texture2D *> textures;
} TexturesContainer;

void textures_container_add_texture(TexturesContainer *container, TexturesNames name, Texture2D *texture);
Texture2D *textures_container_get_textures(TexturesContainer *container, TexturesNames name);
void textures_container_clear(TexturesContainer *container, TexturesNames name, int size);

#endif // TEXTURESCONTAINER_H_