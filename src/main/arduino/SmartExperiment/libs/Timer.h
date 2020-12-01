#ifndef __TIMER_H_
#define __TIMER_H_

class Timer {
    
public:  
     Timer();
     void setupFreq(int freq);  
     void setupPeriod(int period); // ms 
     void waitForNextTick();
};

#endif  // __TIMER_H_