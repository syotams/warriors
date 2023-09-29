#pragma once
#ifndef KNIGHT_STATES_HEADER
#define KNIGHT_STATES_HEADER

enum class KnightStates
{
    Idle,
    Walk,
    Run,
    Attack,
    Jump,
    JumpAttack,
    Dead
};

#endif