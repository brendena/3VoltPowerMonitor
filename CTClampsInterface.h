#ifndef CTClampsInterface_h
#define CTClampsInterface_h
#include "Arduino.h"
class CTClampsInterface  {

  public:
   
    // pure virtual function providing interface framework.
    CTClampsInterface(int Pin){
      pin = Pin;
      cumulativeAmps = 0;
    }
    
    virtual void readPin();
    ~CTClampsInterface() {};
    void reset(){
     cumulativeAmps = 0; 
    }
    double  averageCumulativeAmps(int numberInterations){
      return cumulativeAmps / numberInterations;
    }
    
    int pin;
    double cumulativeAmps;

};

#endif
