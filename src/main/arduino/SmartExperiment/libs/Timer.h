#ifndef __TIMER_H_
#define __TIMER_H_

class Timer {

public:  
     static Timer *getInstance();
     void setupFreq(uint32_t freq);     // Hz
     void setupPeriod(uint32_t period); // ms
     void attachInterrupt(void(*isr)(void));
     void detachInterrupt();

private:
     void (*getCallback(void))(void);
     static Timer *SINGLETON;
     Timer();
     void (*_isrCallback)(void);
};

#endif  // __TIMER_H_