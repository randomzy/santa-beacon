#include "common/pixel.h"

uint8_t RGB::*rgb[] = {&RGB::r, &RGB::g, &RGB::b};

uint8_t &RGB::operator[](unsigned int id)
{
    if (id > 3)
    {
    }
    uint8_t RGB::*color = rgb[id];
    return *this.*color;
}

uint8_t const &RGB::operator[](unsigned int id) const
{
    if (id > 3)
    {
    }
    uint8_t RGB::*color = rgb[id];
    return *this.*color;
}
