#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include "libSonar.h"

using namespace std;

const uint8_t trigger = 19;
const uint8_t echo = 26;

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
