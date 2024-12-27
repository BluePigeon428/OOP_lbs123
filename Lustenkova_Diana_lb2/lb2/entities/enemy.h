#include "entity.h"

class enemy : public entity
{
private:
protected:
public:
    enemy();
    cords step_to_move_to_player(int my_x, int my_y, int p_x, int p_y);
};