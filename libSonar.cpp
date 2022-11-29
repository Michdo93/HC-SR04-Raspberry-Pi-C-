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
}

double Sonar::distance()
{
    gpioSetMode(trigger, PI_HIGH);

    gpioDelay(10);
    gpioSetMode(trigger, PI_LOW);

    double startTime = time_time();
    double arrivalTime = time_time();

    while(gpioRead(echo) == PI_LOW) {
        startTime = time_time();
    }

    while(gpioRead(echo) == PI_HIGH) {
        arrivalTime = time_time();
    }

    double timeElapsed = arrivalTime - startTime;
    double distanceCalculated = (timeElapsed * 34300) / 2;

    return distanceCalculated;
}
