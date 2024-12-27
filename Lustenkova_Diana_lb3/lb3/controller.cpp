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

void controller::set_cords_(int x, int y)
{
    cords_.x_ = x;
    cords_.y_ = y;
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

    // if Spikes
    if (f.touch_cell(cords_.x_, cords_.y_) == Spikes)
    {
        e.add_lives_(-100);
    }
    // if Teleport
    if (f.touch_cell(cords_.x_, cords_.y_) == Teleport)
    {
        cords_ = f.get_tp_cords_of_cell(cords_.x_, cords_.y_);
    }

    // events
    f.do_event_of_cell(cords_.x_, cords_.y_, *this);
    f.remove_event_of_cell(cords_.x_, cords_.y_);
}

// the entity methods needed above

void controller::add_lives_(int how_many) {
    e.add_lives_(how_many);
}

// the field methods needed above

uint32_t controller::get_height_() {
    return f.get_height_();
}

uint32_t controller::get_width_() {
    return f.get_width_();
}

void controller::set_type_of_cell(int x, int y, cell_type type) {
    f.set_type_of_cell(x, y, type);
}

void controller::set_tp_cords_of_cell(int x, int y, cords tp_cords) {
    f.set_tp_cords_of_cell(x, y, tp_cords);
}

cell_type controller::touch_cell(int x, int y) {
    return f.touch_cell(x, y);
}

cords controller::get_tp_cords_of_cell(int x, int y) {
    return f.get_tp_cords_of_cell(x, y);
}