#include "textures_container.h"

void textures_container_add_texture(TexturesContainer *container, TexturesNames name, Texture2D *texture)
{
    container->textures.insert(std::make_pair(name, texture));
}

Texture2D *textures_container_get_textures(TexturesContainer *container, TexturesNames name)
{
    std::map<TexturesNames, Texture2D *>::iterator itr = container->textures.find(name);
    if (itr != container->textures.end())
    {
        return itr->second;
    }
    return nullptr;
}

void textures_container_clear(TexturesContainer *container, TexturesNames name, int size)
{
    char message[100];
    snprintf(message, 100, "textures_container_clear: clean textures of %d", name);
    log(message);
    Texture2D *texture = textures_container_get_textures(container, name);
    for (int i = 0; i < size; i++)
    {
        snprintf(message, 100, "textures_container_clear: clean texture[%d]", i);
        log(message);
        UnloadTexture(texture[i]);
    }
}