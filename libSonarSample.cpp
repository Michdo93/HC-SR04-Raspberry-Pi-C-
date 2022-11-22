#include <iostream>
#include <stdio.h>
#include <pigpio.h>
#include "libSonar.h"

using namespace std;

int trigger = 4;
int echo = 5;

int main()
{
    if (gpioInitialise() == -1)
        return -1;

    Sonar sonar;
    sonar.init(trigger, echo);

    while(1){
        cout << "Distance is " << sonar.distance(30000) << " cm." << endl;
    }
}
