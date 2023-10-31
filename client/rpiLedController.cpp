#include "rpiLedController.h"
#include "common/config.h"
#include "common/pixel.h"
#include <ws2811.h>

RpiLedController::RpiLedController()
{
    m_context.freq = WS2811_TARGET_FREQ;
    m_context.dmanum = 10;
    // PWM channel 0
    m_context.channel[0] = {
        .gpionum = LED_PIN,
        .invert = 0,
        .count = LED_COUNT,
        .strip_type = WS2811_STRIP_RGB,
        .brightness = 255,
    };
    // PWM channel 1
    m_context.channel[1] = {
        .gpionum = 0,
        .invert = 0,
        .count = 0,
        .brightness = 0,
    };
    ws2811_init(&m_context);
}

RpiLedController::~RpiLedController()
{
    ws2811_fini(&m_context);
}

void RpiLedController::render()
{
    ws2811_render(&m_context);
}

static inline uint32_t rgbToPacked(RGB const &rgb)
{
    // WRGB
    return (rgb.r << 16) | (rgb.g << 8) | rgb.b;
}

void RpiLedController::setPixels(RGB const *colors, size_t start, size_t cnt)
{
    for (size_t i = start; i < start + cnt; i++)
    {
        m_context.channel[0].leds[i] = rgbToPacked(colors[i]);
    }
}

void RpiLedController::setPixel(size_t index, RGB const &color)
{
    m_context.channel[0].leds[index] = rgbToPacked(color);
}
