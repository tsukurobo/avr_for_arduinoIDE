#ifndef IMD_STATE_H
#define IMD_STATE_H

#include "Arduino.h"

// encoder value
extern volatile int32_t counter;
// -100 <= power <= 100
extern volatile int8_t power;
extern volatile float pid_target;

#endif

