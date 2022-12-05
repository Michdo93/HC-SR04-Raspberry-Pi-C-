#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(const uint8_t &trigger, const uint8_t &echo);
    double distance();

  private:
    uint8_t trigger;
    uint8_t echo;
    double startTime;
    double arrivalTime;
    double timeElapsed;
    double distanceCalculated;
    double distance1;
    double distance2;
    double speedMeasured;
};

#endif
