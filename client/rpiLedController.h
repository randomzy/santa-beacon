#ifndef RPILEDCONTROLLER_H_
#define RPILEDCONTROLLER_H_

#include "common/config.h"
#include "ledControllerInterface.h"
#include "ws2811.h"
#include <array>

class RpiLedController : public ILedController
{
  public:
    RpiLedController();
    ~RpiLedController();

    void render() override;
    void setPixels(RGB const *colors, size_t start, size_t cnt) override;
    void setPixel(size_t index, RGB const &color) override;

  private:
    std::array<ws2811_led_t, LED_COUNT> m_leds;
    ws2811_t m_context;
};

#endif /* RPILEDCONTROLLER_H_ */
