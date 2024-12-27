#include "entities/player.h"
#include "entities/enemy.h"

enum Direction { Top, Bottom, Right, Left };

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
    void move(Direction move_direction);
};