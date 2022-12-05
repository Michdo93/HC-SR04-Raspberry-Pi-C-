#include <iostream>
#include <stdio.h>
#include <pigpio.h>
#include "libSonar.h"

using namespace std;

uint8_t trigger = 19;
uint8_t echo = 26;

int main()
{
    if (gpioInitialise() == -1)
        return -1;

    Sonar sonar;
    sonar.init(trigger, echo);

    while(1){
        cout << "Distance is " << sonar.distance() << " cm." << endl;
        usleep(1000000);
    }
}
