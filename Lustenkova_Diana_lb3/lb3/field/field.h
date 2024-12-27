#pragma once

#include "cell.h"
#include <cstdint>

class field
{
private:
    // memory operations
    void allocate_field();
    void deallocate_field();
    //
    uint32_t height_;
    uint32_t width_;
    cords entrance_;
    cords exit_;
    cell** cells_;
protected:
public:
    field(uint32_t h = 25, uint32_t w = 25, cords entrance = { 12, 1 });
    //copying
    void copy(const field& other);
    field(const field& other);
    field& operator = (const field& obj);
    // move
    void move(field&& other);
    field(field&& other);
    field& operator = (field&& obj);
    // getters and setters
    uint32_t get_height_();
    uint32_t get_width_();
    cords get_entrance_();
    cords get_exit_();
    void set_exit_(cords exit_cords);
    void set_type_of_cell(int x, int y, cell_type type);
    cell_type touch_cell(int x, int y);
    cords get_tp_cords_of_cell(int x, int y);
    void set_tp_cords_of_cell(int x, int y, cords tp_cords);
    // events
    void set_event_of_cell(int x, int y, event* event);
    void  do_event_of_cell(int x, int y, controller& c);
    void remove_event_of_cell(int x, int y);
    // std::cout
    void str();
    ~field();
};