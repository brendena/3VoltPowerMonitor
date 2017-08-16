#ifndef CTContainer_h
#define CTContainer_h

#include "./CTClampsInterface.h"
#include "./TedClamps.h"
#include "./YHDCClamps.h"

class CTContainer {
  private:
    CTClampsInterface * listCTClamps[4];

    int numberIterations = 0;
    const int sizeOfContainer = 4;
  public:
    CTContainer(){
      
      listCTClamps[0] = new TedClamp(5);
      listCTClamps[1] = new TedClamp(6);
      listCTClamps[2] = new YHDCClamp(1);
      listCTClamps[3] = new YHDCClamp(2);
    }
    /*
    void add(CTClampsInterface ctClamps[])
    {
      int i = 0;
      for(i; i < sizeOfContainer; i++)
      {
        //listCTClamps[i] = ctClamps[i];
      }
    }
    */
  
    void readClamps(){
      int i = 0;
      for(i; i < sizeOfContainer; i++)
      {
        listCTClamps[i]->readPin();
      }
      numberIterations++;
    }

    void calculateAverages(){
      
      int ampValues[2];
      ampValues[0] = listCTClamps[0]->averageCumulativeAmps(numberIterations) + listCTClamps[1]->averageCumulativeAmps(numberIterations);
      ampValues[1] = listCTClamps[2]->averageCumulativeAmps(numberIterations) + listCTClamps[3]->averageCumulativeAmps(numberIterations);
      Serial.println("{\"home\": " + String(ampValues[0]) + 
                     ",\"garage\": " + String(ampValues[1]) + "  }");
      /*
      int i = 0;
      for(i; i < sizeOfContainer; i++)
      {
        
        Serial.print(listCTClamps[i]->averageCumulativeAmps(numberIterations));
        Serial.print(" - ");
      }
      */
    }
  
    void resetClamps()
    {
      int i = 0;
      for(i; i < sizeOfContainer; i++)
      {
        listCTClamps[i]->reset();
      }
      numberIterations = 0;
    }
    
};
#endif

