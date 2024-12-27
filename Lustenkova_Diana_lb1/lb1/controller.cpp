#include "controller.h"

controller::controller(entity& somebody, field& somewhere, cords xy)
    : e{ somebody },
    f{ somewhere },
    cords_{ xy }
{
    // Now we can manage events
}

cords controller::get_cords_()
{
    return cords_;
}

void controller::move(Direction move_direction)
{
    if (move_direction == Top) {
        if (f.touch_cell(cords_.x_, cords_.y_ + 1) != Barrier)
            cords_.y_ += 1;
    }
    if (move_direction == Bottom) {
        if (f.touch_cell(cords_.x_, cords_.y_ - 1) != Barrier)
            cords_.y_ -= 1;
    }
    if (move_direction == Right) {
        if (f.touch_cell(cords_.x_ + 1, cords_.y_) != Barrier)
            cords_.x_ += 1;
    }
    if (move_direction == Left) {
        if (f.touch_cell(cords_.x_ - 1, cords_.y_) != Barrier)
            cords_.x_ -= 1;
    }
}