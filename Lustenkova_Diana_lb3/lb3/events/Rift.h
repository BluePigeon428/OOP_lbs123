#pragma once

#include "event.h"

// Moving around the map

class Rift : public event
{ // A rift in the continuum teleporting to an indeterminate point
public:
    void do_event(controller& c) final;
    event* copy() final;
};