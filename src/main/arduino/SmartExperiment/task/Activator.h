#ifndef __ACTIVATOR_H_
#define __ACTIVATOR_H_

#include "SmartExperiment.h"
#include "Activable.h"
#define MAX_ACTIVABLES 50

class Activator {

public:
     bool addTask(Activable* activable){
          if (nActivables < MAX_ACTIVABLES - 1){
               attachedActivables[nActivables] = activable;
               nActivables++;
               return true;
          } else
               return false; 
     }
 
private:
     void setActiveAll(bool active) {
          for (uint16_t i = 0; i < nActivables; i++) {
               attachedActivables[i]->setActive(active);
          }
     }
     bool active;
     uint16_t nActivables;
     Activable* attachedActivables[MAX_ACTIVABLES];
 
};

#endif // __ACTIVATOR_H_

