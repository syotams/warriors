#pragma once
#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <algorithm>
#include "../Constants.h"

void log(const char *message);
void info(const char *message);
void debug(const char *message);

#endif // LOG_H_