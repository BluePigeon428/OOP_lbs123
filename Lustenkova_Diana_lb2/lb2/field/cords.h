#include <iostream>

enum cell_type { Floor, Spikes, Barrier, Teleport, Exit_door };

struct cords
{
    int x_;
    int y_;
};