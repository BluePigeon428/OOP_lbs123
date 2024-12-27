#include "field.h"

// memory operations

void field::allocate_field()
{
    cells_ = new cell * [height_];
    for (int y = 0; y < height_; y++)
    {
        cells_[y] = new cell[width_];
    }
}

void field::deallocate_field()
{
    if (cells_ != nullptr)
    {
        for (int y = 0; y < height_; y++)
        {
            for (int x = 0; x < width_; x++)
            {
                cells_[y][x].remove_event_();
            }
            delete[] cells_[y];
        }
        delete[] cells_;
    }
    cells_ = nullptr;
}

//

field::field(uint32_t h, uint32_t w, cords entrance)
    : height_(h), width_(w), entrance_(entrance), exit_({ -1, -1 })
{
    // Exception
    if (h < 5 || w < 5)
    {
        std::cerr << "The size of the field is not correct" << '\n';
    }
    // Normal work
    allocate_field();
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            if (x == 0 || y == 0 || x == width_ - 1 || y == height_ - 1)
                cells_[y][x].set_type_(Barrier);
        }
    }
}

//copying

void field::copy(const field& other)
{
    if (this != &other)
    {
        height_ = other.height_;
        width_ = other.width_;
        entrance_ = other.entrance_;
        exit_ = other.exit_;

        allocate_field();

        for (int y = 0; y < height_; y++)
        {
            for (int x = 0; x < width_; x++)
                cells_[y][x] = other.cells_[y][x];
        }
    }
}

field::field(const field& other)
{
    copy(other);
}

field& field::operator = (const field& obj)
{
    copy(obj);
    return *this;
}

//

// move

void field::move(field&& other)
{
    if (this != &other)
    {
        height_ = other.height_;
        width_ = other.width_;
        entrance_ = other.entrance_;
        exit_ = other.exit_;
        std::swap(cells_, other.cells_);
        other.cells_ = nullptr;
    }
}

field::field(field&& other)
{
    move(std::move(other));
}

field& field::operator = (field&& obj)
{
    move(std::move(obj));
    return *this;
}

//

// getters and setters

uint32_t field::get_height_()
{
    return height_;
}

uint32_t field::get_width_()
{
    return width_;
}

cords field::get_entrance_()
{
    return entrance_;
}

cords field::get_exit_()
{
    return exit_;
}

void field::set_exit_(cords exit_cords)
{
    exit_ = exit_cords;
    cells_[exit_cords.y_][exit_cords.x_].set_type_(Exit_door);
}

void field::set_type_of_cell(int x, int y, cell_type type)
{
    cells_[y][x].set_type_(type);
}

cell_type field::touch_cell(int x, int y) 
{
    return cells_[y][x].get_type_();
}

cords field::get_tp_cords_of_cell(int x, int y)
{
    return cells_[y][x].get_tp_cords_();
}

void field::set_tp_cords_of_cell(int x, int y, cords tp_cords) {
    cells_[y][x].set_tp_cords_(tp_cords);
}

//

// events

void field::set_event_of_cell(int x, int y, event* event) {
    cells_[y][x].set_event_(event);
}

void field::do_event_of_cell(int x, int y, controller& c) {
    cells_[y][x].do_event_(c);
}

void field::remove_event_of_cell(int x, int y) {
    cells_[y][x].remove_event_();
}

// std::cout

void field::str()
{
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            std::cout << cells_[y][x].get_type_() << ' ';
        }
        std::cout << '\n';
    }
}
//

// Destructor

field::~field()
{
    deallocate_field();
}