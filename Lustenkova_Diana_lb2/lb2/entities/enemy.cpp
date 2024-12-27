#include "enemy.h"

enemy::enemy()
{

}

cords enemy::step_to_move_to_player(int my_x, int my_y, int p_x, int p_y)
{
    int x1 = my_x; // enemy x
    int y1 = my_y; // enemy y
    int x2 = p_x;  // player x
    int y2 = p_y;  // player y

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int d = dx - dy;

    int x1_is_lower_x2; int y1_is_lower_y2;
    if (x1 < x2)
        x1_is_lower_x2 = 1;
    else
        x1_is_lower_x2 = -1;
    if (y1 < y2)
        y1_is_lower_y2 = 1;
    else
        y1_is_lower_y2 = -1;

    int x = x1; int y = y1;
    while (x != x2 || y != y2)
    {
        int doble_d = 2 * d;
        if (doble_d > -dy)
        {
            d -= dy;
            x += x1_is_lower_x2;
        }
        if (doble_d < dx)
        {
            d += dx;
            y += y1_is_lower_y2;
        }

        return { x, y };
    }
}