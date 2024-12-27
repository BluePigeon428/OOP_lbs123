#include "cell.h"

cell::cell(cell_type type, cords tp)
    : type_(type)
{
    if (type_ == Teleport)
        tp_cords_ = tp;
}

cell::cell() : type_(Floor) {}

void cell::set_type_(cell_type type)
{
    type_ = type;
}

cell_type cell::get_type_()
{
    return type_;
}

cords cell::get_tp_cords_()
{
    if (type_ == Teleport)
        return tp_cords_;
}
