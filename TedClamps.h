#ifndef TedClamps_h
#define TedClamps_h
#include "Arduino.h"
#include "./CTClampsInterface.h"
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-----Ted-Clamps------------------
Ted clamps produce a voltage from
0 - 3 volts AC.  
  where 
    0 - 0 AMPS
    0 - 200 AMPS 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
class TedClamp : public CTClampsInterface
{
  public:
    const int maxAmps = 200;
    const int numberOfReadingg = 200;
    unsigned long tmpCumulativeAnalogRead = 0;
    unsigned int tmpAnalogRead = 0;
    TedClamp(int Pin):CTClampsInterface(Pin){
    }

    void readPin(){
      tmpCumulativeAnalogRead = 0;
      tmpAnalogRead = 0;
      int numberZero = 0;
      for (unsigned int n = 0; n < numberOfReadingg; n++)
      {
        while(numberZero < 200){
          tmpAnalogRead = analogRead(pin);
          if(tmpAnalogRead > 1 ){
            tmpCumulativeAnalogRead += tmpAnalogRead * tmpAnalogRead;
            break;
          }
          else{
              numberZero++;
          }
        }
      }
      if(numberZero < 200)
      {
        tmpCumulativeAnalogRead = sqrt(tmpCumulativeAnalogRead/numberOfReadingg);
        cumulativeAmps += map(tmpCumulativeAnalogRead, 0, 1023, 0, maxAmps);
      }
    }
};

#endif

