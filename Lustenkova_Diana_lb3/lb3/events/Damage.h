#pragma once

#include "event.h"

// A negative event for the entity

class Damage : public event
{ // Continuum shift of energies
public:
    void do_event(controller& c) final;
    event* copy() final;
};
