#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(int trigger, int echo);
    double distance();

  private:
    int trigger;
    int echo;
    double startTime;
    double arrivalTime;
    double timeElapsed;
    double distanceCalculated;
};

#endif
