/****************************************************************
 * 
 * This Example is used to test leds
 * 
 * Arduino tools Setting 
 * -board : M5StickC
 * -Upload Speed: 115200 / 750000 / 1500000
 * 
****************************************************************/
#include "M5AtomLite.h"

void setup()
{
    M5.begin(true, false, true);
    delay(50);
    M5.dis.drawpix(0, CRGB::Red);
}

uint8_t FSM = 0;

void loop()
{
    if (M5.Btn.wasPressed())
    {
        FSM++;
        if (FSM >= 4)
        {
            FSM = 0;
        }

        switch (FSM)
        {
        case 0:
            M5.dis.drawpix(0, CRGB::Red);
            break;
        case 1:
            M5.dis.drawpix(0, CRGB::Green);
            break;
        case 2:
            M5.dis.drawpix(0, CRGB::Blue);
            break;
        case 3:
            M5.dis.drawpix(0, CRGB::White);
            break;
        default:
            break;
        }
    }

    delay(50);
    M5.update();
}