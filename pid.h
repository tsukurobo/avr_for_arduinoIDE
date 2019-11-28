#ifndef IMD_PID_H
#define IMD_PID_H

#include "config.h"

class PIDController {
  public:
    PIDController(float Kp, float Ki, float Kd, Config& cfg);

    float update(float target);

  private:
    Config cfg;
    float Kp, Ki, Kd;
    float I;
    float enc_prev;
    unsigned long long time_prev;
    float prev_e; // 過去の偏差
};

#endif

