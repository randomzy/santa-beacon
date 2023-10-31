#ifndef LEDCONTROLLER_H_
#define LEDCONTROLLER_H_

#include "common/pixel.h"

class ILedController
{
  public:
    ILedController(){};
    ILedController(ILedController const &) = delete;
    ILedController &operator=(ILedController const &) = delete;

    virtual ~ILedController(){};
    virtual void render() = 0;
    virtual void setPixels(RGB const *colors, size_t start, size_t cnt) = 0;
    virtual void setPixel(size_t index, RGB const &color) = 0;
};

#endif /* LEDCONTROLLER_H_ */
