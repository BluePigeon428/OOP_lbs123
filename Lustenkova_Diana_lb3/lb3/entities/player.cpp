#include "player.h"

player::player()
    : level_{ 1 }
{

}

void player::kill()
{
    level_ = 0;
}

void player::raise_power(int raise)
{
    attack_power_ += raise;
}

void player::levelup()
{
    if (alive_)
    {
        level_ += 1;
        lives_ += 100;
        attack_power_ += 10;
    }
}