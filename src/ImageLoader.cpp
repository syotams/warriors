#include "ImageLoader.h"

std::array<int, 2> scale_image(int width, int height, int to_size)
{
    int _width = 0, _height = 0;
    if (width > height)
    {
        _height = to_size * height / width;
        _width = to_size;
    }
    else
    {
        _width = to_size * width / height;
        _height = to_size;
    }
    return {_width, _height};
}

std::array<Texture2D *, 2> load_lr_animated_images(int size, char *file_name)
{
    std::array<Texture2D *, 2> result;
    // TODO: Creating a new instance here is a dedicated to memory leakage, find another solution?
    Texture2D *rightSidedTextures = new Texture2D[10];
    Texture2D *leftSidedTextures = new Texture2D[10];

    for (int i = 0; i < size; i++)
    {
        char file[100];
        snprintf(file, 100, file_name, i + 1);

        Image image = LoadImage(file);
        rightSidedTextures[i] = LoadTextureFromImage(image); // 587x707
        ImageFlipHorizontal(&image);

        leftSidedTextures[i] = LoadTextureFromImage(image);
        UnloadImage(image);

        std::array<int, 2> new_size = scale_image(rightSidedTextures[i].width, rightSidedTextures[i].height, TEXTURE_SIZE);
        rightSidedTextures[i].width = new_size[0];
        rightSidedTextures[i].height = new_size[1];
        leftSidedTextures[i].width = new_size[0];
        leftSidedTextures[i].height = new_size[1];
    }

    result[0] = rightSidedTextures;
    result[1] = leftSidedTextures;
    return result;
}
