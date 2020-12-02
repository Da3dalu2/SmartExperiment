#include "Timer.h"

Timer *Timer::SINGLETON {};

Timer::Timer(){
    this->_isrCallback = emptyCallback;
}

Timer *Timer::getInstance() {
    return SINGLETON;
}

void emptyCallback(void) {}

void Timer::setupFreq(uint32_t freq){
  cli();

  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  
  /* 
   * set compare match register
   * 
   * OCR1A = (16*2^20) / (100*PRESCALER) - 1 (must be < 65536)
   *
   * assuming a prescaler = 1024 => OCR1A = (16*2^10)/freq 
   */
  OCR1A = 16*1024/freq; 
  TCCR1B |= (1 << WGM12); // turn on CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10);  // Set CS11 for 8 prescaler
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

  sei();
}

void Timer::setupPeriod(uint32_t period){
  cli();
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  
  /* 
   * set compare match register
   * 
   * OCR1A = (16*2^20) / (100*PRESCALER) - 1 (must be < 65536)
   *
   * assuming a prescaler = 1024 => OCR1A = (16*2^10)* period/1000 (being in ms) 
   */
  OCR1A = 16.384*period; 
  TCCR1B |= (1 << WGM12); // turn on CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // Set CS11 for 8 prescaler
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

  sei();
}

void Timer::attachInterrupt(void(*isr)(void)) {
    this->_isrCallback = isr; // Setting the function to be called on the interrupt capture
    TIMSK1 |= _BV(OCIE1A);    // Enabling interrupts capture
}

void Timer::detachInterrupt() {
    TIMSK1 = 0;                         // Disabling interrupts capture
    this->_isrCallback = emptyCallback; // Resetting function called on interrupt to an empty one
}

void (*Timer::getCallback(void))(void) {
    return this->_isrCallback;
}

ISR(TIMER1_COMPA_vect){
  (Timer.getCallback())();
}
