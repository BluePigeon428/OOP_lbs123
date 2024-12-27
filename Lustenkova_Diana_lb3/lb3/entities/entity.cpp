#include "entity.h"

entity::entity()
    : alive_{ true },
    lives_{ 100 },
    attack_power_{ 10 }
{

}

void entity::kill()
{
    alive_ = false;
    lives_ = 0;
}

void entity::add_lives_(int how_many)
{
    if (alive_)
    {
        lives_ += how_many;
        if (lives_ <= 0)
            this->kill();
    }
}

uint32_t entity::get_lives_()
{
    return lives_;
}