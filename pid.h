#ifndef IMD_PID_H
#define IMD_PID_H

#include "config.h"

class PIDConfig {
  public:
    PIDConfig(float Kp, float Ki, float Kd, PIDMode mode)
      : Kp(Kp), Ki(Ki), Kd(Kd), mode(mode) {};
    float Kp, Ki, Kd;
    // add read_from_i2c
    PIDMode mode;
};

class PIDController {
  public:
    PIDController(Config& cfg, PIDConfig& pcfg)
      : cfg(cfg), pcfg(pcfg), I(0), enc_prev(0),
        time_prev(0), prev_e(0) {};

    float update(float target);

  private:
    Config& cfg;
    PIDConfig& pcfg;
    float I;
    float enc_prev;
    unsigned long long time_prev;
    float prev_e; // 過去の偏差
};

#endif

