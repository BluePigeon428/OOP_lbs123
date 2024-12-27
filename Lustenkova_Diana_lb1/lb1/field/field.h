#include "cell.h"

class field
{
private:
protected:
    unsigned int height_;
    unsigned int width_;
    cell** cells_;
public:
    field(unsigned int h, unsigned int w);
    field();
    field copy();
    bool touch_cell(int x, int y);
    ~field();
};