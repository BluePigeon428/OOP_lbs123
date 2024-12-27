#include "cell.h"

cell::cell(bool wall)
    : barrier_{ wall }
{
    // barrier = wall;
};

cell::cell()
    : barrier_{ false }
{

};

bool cell::touch()
{
    return barrier_;
};
