#include "entities/player.h"
#include "entities/enemy.h"

class controller
{
private:
protected:
    entity& e;
    field& f;
    cords cords_;
public:
    controller(entity& somebody, field& somewhere, cords xy);
    cords get_cords_();
    void set_cords_(int x, int y);
    void move(Direction move_direction);
    // the entity methods needed above
    void add_lives_(int how_many);
    // the field methods needed above
    uint32_t get_height_();
    uint32_t get_width_();
    void set_type_of_cell(int x, int y, cell_type type);
    void set_tp_cords_of_cell(int x, int y, cords tp_cords);
    cell_type touch_cell(int x, int y);
    cords get_tp_cords_of_cell(int x, int y);
};