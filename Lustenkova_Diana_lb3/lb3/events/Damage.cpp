#include "Damage.h"
#include "../controller.h"

// A negative event for the entity

void Damage::do_event(controller& c)
{
    c.add_lives_(DAMAGE);
}

event* Damage::copy()
{
    return new Damage;
}