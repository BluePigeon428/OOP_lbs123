#include "Healing.h"
#include "../controller.h"

// A positive event for the entity

void Healing::do_event(controller& c)
{
    c.add_lives_(HEALING);
}

event* Healing::copy()
{
    return new Healing;
}
