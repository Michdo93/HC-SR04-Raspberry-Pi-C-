#include <iostream>
#include <stdio.h>
#include <pigpio.h>
#include "libSonar.h"

Sonar::Sonar(){}

void Sonar::init(int trigger, int echo)
{
    this->trigger=trigger;
    this->echo=echo;
    gpioSetMode(trigger, PI_OUTPUT);
    gpioSetMode(echo, PI_INPUT);

    gpioWrite(trigger, PI_LOW);
    delay(500);
}

double Sonar::distance(int timeout)
{
    delay(10);

    gpioWrite(trigger, PI_HIGH);
    delayMicroseconds(10);
    gpioWrite(trigger, PI_LOW);

    now=micros();

    while (digitalRead(echo) == PI_LOW && micros()-now<timeout);
        recordPulseLength();

    travelTimeUsec = endTimeUsec - startTimeUsec;
    distanceMeters = 100*((travelTimeUsec/1000000.0)*340.29)/2;

    return distanceMeters;
}

void Sonar::recordPulseLength()
{
    startTimeUsec = micros();
    while ( digitalRead(echo) == PI_HIGH );
    endTimeUsec = micros();
}
