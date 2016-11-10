#ifndef GPS_h
#define GPS_h

#include <string>

class GPS
{
  public:
    GPS();
    void getLocation();
    void parseData(float*);
    float* createLocArray(string);
    
  private:
    Serial* gps;
};

#endif

