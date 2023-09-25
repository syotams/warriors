#pragma once
#ifndef CONSTRAIN_HADER
#define CONSTRAIN_HADER

#include <iostream>

class Constrain
{
public:
    virtual void apply() = 0;
    virtual ~Constrain(){};
};
#endif