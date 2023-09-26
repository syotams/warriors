#pragma once
#ifndef IMAGE_LOADER_HEADER
#define IMAGE_LOADER_HEADER

#include <iostream>
#include "raylib.h"
#include "Constants.h"

std::array<Texture2D *, 2> load_lr_animated_images(const int size, char *file_name, const int scale);

#endif