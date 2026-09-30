# 1 "C:\\Users\\2156790\\AppData\\Local\\Temp\\tmpihhlw2dn"
#include <Arduino.h>
# 1 "C:/Users/2156790/Documents/arduino_arcade_osc_unity/arduino_arcade_osc_unity.ino"
#include <Arduino.h>

#include <Bounce2.h>
Bounce2::Button but0;

#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);
void setup();
void loop();
#line 9 "C:/Users/2156790/Documents/arduino_arcade_osc_unity/arduino_arcade_osc_unity.ino"
void setup()
{
    Serial.begin(115200);

    but0.attach(2, INPUT_PULLUP);
    but0.setPressedState(LOW);

    pinMode(3, OUTPUT);

}

void loop()
{
    but0.update();


    if (but0.pressed()) {







        monOsc.sendInt("/but0", 1);
    }

    if (but0.released()) {







        monOsc.sendInt("/but0", 0);
    }

    if (but0.isPressed()) {
        digitalWrite( 3 , HIGH );
    } else {
        digitalWrite( 3 , LOW );
    }

}