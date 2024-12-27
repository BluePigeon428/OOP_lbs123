#include "cords.h"

// a cell is a unit of a field

class cell
{
private:
    cell_type type_;
    cords tp_cords_;
protected:
public:
    cell(cell_type type, cords tp = { 1, 1 });
    cell();
    void set_type_(cell_type type);
    cell_type get_type_();
    cords get_tp_cords_();
};