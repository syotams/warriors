#include "Log.h"

void log(const char *message)
{
    if (LOG_LEVEL == "debug")
    {
        debug(message);
    }
    else
    {
        info(message);
    }
}

void info(const char *message)
{
    std::cout << "\033[37;47m" << message << "\033[0m" << std::endl;
}

void debug(const char *message)
{
    std::cout << "\033[32m" << message << "\033[0m" << std::endl;
}
