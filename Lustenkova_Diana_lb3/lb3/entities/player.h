#include "entity.h"

class player : public entity
{
private:
protected:
    uint32_t level_;
public:
    player();
    void kill();
    void raise_power(int raise);
    void levelup();
};