
# the compiler: define as g++ for C++
CC = g++
 
# compiler flags:
CFLAGS = -Wall -pthread
LFLAGS = -lpigpio -lrt
 
# The build target 
TARGET = libSonarSample.cpp libSonar.cpp
EXECUTABLE = testSonar
 
all: $(EXECUTABLE)
 
$(EXECUTABLE): sudo ./$(EXECUTABLE)
            $(CC) $(CFLAGS) $(TARGET) -o $(EXECUTABLE) $(LFLAGS)
 
clean:
            $(RM) $(EXECUTABLE)
