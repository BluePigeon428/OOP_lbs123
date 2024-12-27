#ifndef ENTITY_H
#define ENTITY_H


#include "../field/field.h"
#include <cstdint>//


class entity
{
private:
protected:
    bool alive_;
    uint32_t lives_;
    uint32_t attack_power_;

public:
    entity();
    void kill();
    void add_lives_(int how_many);
    uint32_t get_attack_power_();
};

#endif