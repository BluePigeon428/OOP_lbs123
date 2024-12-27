#include "field.h"

field::field(unsigned int h, unsigned int w)
    : height_{ h }, width_{ w }
{
    // Exception
    if (h < 10 || w < 10)
    {
        std::cout << "The sizes of the field are not correct" << '\n';
    }
    // Normal work
    cells_ = new cell * [height_];
    for (int y = 0; y < height_; y++)
    {
        cells_[y] = new cell[width_];
        for (int x = 0; x < width_; x++)
        {
            if (x == 0 || y == 0)
                cells_[y][x] = cell(true);
        }
    }
}

field::field()
    : height_{ 50 }, width_{ 50 }
{
    cells_ = new cell * [height_];
    for (int y = 0; y < height_; y++)
    {
        cells_[y] = new cell[width_];
        for (int x = 0; x < width_; x++)
        {
            if (x == 0 || y == 0)
                cells_[y][x] = cell(true);
        }
    }
};

field field::copy()
{
    field new_f;
    new_f.height_ = height_;
    new_f.width_ = width_;
    new_f.cells_ = new cell * [height_];;
    for (int y = 0; y < height_; y++)
    {
        new_f.cells_[y] = new cell[width_];
        for (int x = 0; x < width_; x++)
        {
            new_f.cells_[y][x] = cells_[y][x];
        }
    }
    return new_f;
};

bool field::touch_cell(int x, int y)
{
    return cells_[y][x].touch();
};

field::~field()
{
    for (int y = 0; y < height_; y++)
    {
        delete[] cells_[y];
    }
    delete[] cells_;
}