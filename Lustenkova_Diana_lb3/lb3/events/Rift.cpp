#include "Rift.h"
#include "../controller.h"

#define DELTA 15

// Moving around the map

void Rift::do_event(controller& c)
{
    uint32_t start_x = rand() % (c.get_width_() - DELTA) + 1;
    uint32_t start_y = rand() % (c.get_height_() - DELTA) + 1;
    bool br_check = false;
    for (int y = start_y; y < c.get_height_() - 1; y++)
    {
        for (int x = start_x; x < c.get_width_() - 1; x++)
        {
            if (c.touch_cell(x, y) != Barrier && c.touch_cell(x, y) != Teleport)
            {
                //*this = new event;
                c.set_cords_(x, y);
                br_check = true;
                break;
            }
        }
        if (br_check) { break; }
    }
}

event* Rift::copy()
{
    return new Rift;
}