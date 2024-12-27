#pragma once

#include "event.h"

// A positive event for the entity

class Healing : public event
{ // Concentration of continuum energy (allows entity to heal)
public:
    void do_event(controller& c) final;
    event* copy() final;
};