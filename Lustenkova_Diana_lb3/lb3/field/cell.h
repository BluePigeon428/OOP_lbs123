#pragma once

#include "cords.h"

#include "../events/event.h"
#include "../events/Healing.h"
#include "../events/Damage.h"
#include "../events/Rift.h"

#include "cell_type.h"

// a cell is a unit of a field

class cell
{
private:
    cell_type type_;
    cords tp_cords_;
    event* event_;
protected:
public:
    cell(cell_type type, event* event = nullptr, cords tp = { 1, 1 });
    cell();
    // copy
    void copy(const cell& other);
    cell(const cell& other);
    cell& operator = (const cell& obj);
    // getters and setters
    void set_type_(cell_type type);
    cell_type get_type_();
    void set_tp_cords_(cords tp_cords);
    cords get_tp_cords_();
    // work with events
    void set_event_(event* event);
    void do_event_(controller& c);
    // Destructor
    void remove_event_();
    ~cell();
};