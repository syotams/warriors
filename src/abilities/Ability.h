#pragma once
#ifndef ABILITY_H_
#define ABILITY_H_

class Ability
{
public:
    virtual void apply() = 0;
    virtual ~Ability(){};
};

#endif // ABILITY_H_