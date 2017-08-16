#ifndef YHDCClamps_h
#define YHDCClamps_h
#include "Arduino.h"
#include "./CustomEmonLib/EmonLib.h" 
#include "./CTClampsInterface.h"
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-----Ted-Clamps------------------
Ted clamps produce a voltage from
0 - 3 volts AC.  
  where 
    0 - 100 AMPS
    1.5 - 0 AMPS
    3 - 100 AMPS 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
class YHDCClamp : public CTClampsInterface
{
  public:
    const int maxAmps = 100;
    const int numberOfReading = 100;
    EnergyMonitor emon;  
    YHDCClamp(int Pin):CTClampsInterface(Pin){
      emon.current(Pin, 111.1);
    }

    void readPin(){
      cumulativeAmps += emon.calcIrms(numberOfReading); 
    }
};

#endif

