# HC-SR04 Raspberry Pi C++
This class allows you to get datas from the HC-SR04 sensor easily in C++!

## Installation

You have to download and install the [pigpio](https://abyz.me.uk/rpi/pigpio/) library:

```
wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install
```

If the Python part of the install fails it may be because you need the setup tools.

```
sudo apt install python-setuptools python3-setuptools
```

To start the pigpio daemon run

```
sudo pigpiod
```

## Usage

For running the library you can create an example like this:

```
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
```
