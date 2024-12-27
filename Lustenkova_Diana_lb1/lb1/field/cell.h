#include <iostream>
#include "cords.h"

//a cell is a unit of a field

class cell {
private:
    cords tp_cords_;
protected:
    bool barrier_;
public:
    cell(bool wall);
    cell();
    bool touch();
};