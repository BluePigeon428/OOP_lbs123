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
    field(uint32_t h, uint32_t w, cords entrance = { 1, 1 });
    field();
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
    // std::cout
    void str();
    ~field();
};