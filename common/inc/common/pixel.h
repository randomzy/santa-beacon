#ifndef PIXEL_H_
#define PIXEL_H_

#include <cstddef>
#include <cstdint>

struct RGB
{
    uint8_t r, g, b;
    uint8_t const &operator[](unsigned id) const;
    uint8_t &operator[](unsigned id);
};

#endif /* PIXEL_H_ */
