#!/bin/bash
g++ -Wall -pthread libSonarSample.cpp libSonar.cpp -o testSonar -lpigpio -lrt
sudo ./testSonar
