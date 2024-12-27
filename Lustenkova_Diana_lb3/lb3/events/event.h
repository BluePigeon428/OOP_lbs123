#pragma once

#define HEALING 200
#define DAMAGE -200

class controller;

class event
{
public:
    virtual void do_event(controller & c) = 0;
    virtual event* copy() = 0;
    virtual ~event() = default;
};