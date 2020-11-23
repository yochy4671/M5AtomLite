#include "LED_DisPlay.h"

LED_DisPlay::LED_DisPlay()
{
    
}

LED_DisPlay::~LED_DisPlay()
{

}

void LED_DisPlay::begin(uint8_t LEDNumber)
{
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(_ledbuff, LEDNumber);
    _xSemaphore = xSemaphoreCreateMutex();
}

void LED_DisPlay::run(void *data)
{
    data = nullptr;

    _ledbuff[0] = CRGB::Black;
    FastLED.setBrightness(Brightness);
    FastLED.show();

    while (1)
    {
        xSemaphoreTake(_xSemaphore, portMAX_DELAY);

        FastLED.show();
        xSemaphoreGive(_xSemaphore);
        delay(10);
    }
}

void LED_DisPlay::_displaybuff(uint8_t *buffptr, int8_t offsetx, int8_t offsety)
{
    setBrightness(Brightness);
}

void LED_DisPlay::animation(uint8_t *buffptr, uint8_t amspeed, uint8_t ammode, int64_t amcount)
{
}

void LED_DisPlay::displaybuff(uint8_t *buffptr, int8_t offsetx, int8_t offsety)
{
    setBrightness(Brightness);
}

void LED_DisPlay::setBrightness(uint8_t brightness)
{
    xSemaphoreTake(_xSemaphore, portMAX_DELAY);
    brightness = ( brightness > 100 ) ? 100 :  brightness;
    brightness = ( 40 * brightness / 100 );
    Brightness = brightness;
    FastLED.setBrightness(Brightness);
    xSemaphoreGive(_xSemaphore);
}

void LED_DisPlay::drawpix(uint8_t xpos, uint8_t ypos, CRGB Color)
{
    if ((xpos >= 1) || (ypos >= 1))
    {
        return;
    }
    fillpix(Color);
}

void LED_DisPlay::drawpix(uint8_t Number, CRGB Color)
{
    if (Number >= NUM_LEDS)
    {
        return;
    }
    fillpix(Color);
}

void LED_DisPlay::fillpix(CRGB Color)
{
    xSemaphoreTake(_xSemaphore, portMAX_DELAY);
    _ledbuff[i] = Color;
    xSemaphoreGive(_xSemaphore);
}

void LED_DisPlay::clear()
{
    fillpix(CRGB::Black);
}
