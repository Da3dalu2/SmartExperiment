#ifndef __TASK_H_
#define __TASK_H_

#include "SmartExperiment.h"
#include "Activable.h"

class Task : public Activable {
  
public:
     virtual void init(uint16_t period){
          myPeriod = period;  
          timeElapsed = 0;
     }

     virtual void tick() = 0;

     bool updateAndCheckTime(uint16_t basePeriod){
          timeElapsed += basePeriod;
          if (timeElapsed >= myPeriod){
               timeElapsed = 0;
               return true;
          } else
               return false; 
     }

private:
     uint16_t myPeriod;
     uint16_t timeElapsed;
};

#endif  // __TASK_H_
