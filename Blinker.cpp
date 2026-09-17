#include <Blinker.h>
#include <Arduino.h>

Blinker::Blinker(int pin, unsigned long interval, unsigned long startvertraging) {
    _pin = pin;
    _interval = interval;
    _startVertraging = startvertraging;
    _volgendeBlink = millis() + _startVertraging;

    pinMode(_pin, OUTPUT);
}   

int Blinker::kweenie(void) {
    unsigned long nu = millis();
    int retval = false;

    if (nu >= _volgendeBlink) {
        _volgendeBlink = nu + _interval;
        digitalWrite(_pin, !digitalRead(_pin));
        retval =  true;
    } 

    return retval;
}
