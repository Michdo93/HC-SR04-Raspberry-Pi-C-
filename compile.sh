#!/bin/bash
gcc -Wall -pthread -o testSonar libSonarSample.cpp -lpigpio -lrt
./testSonar
