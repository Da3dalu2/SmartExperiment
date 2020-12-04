#ifndef __TIMER_H_
#define __TIMER_H_

class TimerClass {

public:
     void setupFreq(uint32_t freq);     // Hz
     void setupPeriod(uint32_t period); // ms
     void attachInterrupt(void(*isr)(void));
     void detachInterrupt();

private:
     TimerClass();
     void (*getCallback(void))(void);
     void (*_isrCallback)(void);
};

extern TimerClass Timer;

#endif  // __TIMER_H_