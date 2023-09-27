#pragma once
#ifndef IMAGE_LOADER_HEADER
#define IMAGE_LOADER_HEADER

#include <iostream>
#include "raylib.h"
#include "Constants.h"

std::array<int, 2> scale_image(const int width, const int height, const int to_size);
std::array<Texture2D *, 2> load_lr_animated_images(const int size, char *file_name, const int scale);

#endif