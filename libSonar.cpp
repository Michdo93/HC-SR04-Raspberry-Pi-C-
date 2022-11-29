#include <iostream>
#include <stdio.h>
#include <sys/time.h>
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
    gpioDelay(500);
}

double Sonar::time_time()
{
   struct timeval tv;
   double t;

   gettimeofday(&tv, 0);

   t = 1000000 * (double)tv.tv_sec + (double)tv.tv_usec);

   return t;
}

double Sonar::distance(int timeout)
{
    gpioDelay(10);

    gpioWrite(trigger, PI_HIGH);
    gpioDelay(10);
    gpioWrite(trigger, PI_LOW);

    now = time_time();

    while (gpioRead(echo) == PI_LOW && time_time()-now<timeout) {
        recordPulseLength();
    }

    travelTimeUsec = endTimeUsec - startTimeUsec;
    distanceMeters = 100*((travelTimeUsec/1000000.0)*340.29)/2;

    return distanceMeters;
}

void Sonar::recordPulseLength()
{
    startTimeUsec = time_time();
    while (gpioRead(echo) == PI_HIGH) {
        endTimeUsec = time_time();
    }
}
