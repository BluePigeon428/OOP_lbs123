#include "cell.h"

cell::cell(cell_type type, event* event, cords tp)
    : type_(type), event_(event), tp_cords_({ -1, -1 })
{
    if (type_ == Teleport)
        tp_cords_ = tp;
}

cell::cell() : cell(Floor) {}

// copying

void cell::copy(const cell& other)
{
    if (this != &other)
    {
        type_ = other.type_;
        tp_cords_ = other.tp_cords_;
        // copy *event
        if (other.event_ == nullptr)
            event_ = nullptr;
        else
            event_ = other.event_->copy();
    }
}

cell::cell(const cell& other)
{
    copy(other);
}

cell& cell::operator = (const cell& obj)
{
    copy(obj);
    return *this;
}

// getters and setters

void cell::set_type_(cell_type type)
{
    type_ = type;
}

cell_type cell::get_type_()
{
    return type_;
}

void cell::set_tp_cords_(cords tp_cords)
{
    tp_cords_ = tp_cords;
}

cords cell::get_tp_cords_()
{
    if (type_ == Teleport)
        return tp_cords_;
}


// events

void cell::set_event_(event* event)
{
    remove_event_();
    event_ = event;
}

void cell::do_event_(controller& c)
{
    if (event_ != nullptr)
    {
        event_->do_event(c);
    }
}

// Destructor

void cell::remove_event_()
{
    delete event_;
    event_ = nullptr;
}

cell::~cell()
{
    remove_event_();
}