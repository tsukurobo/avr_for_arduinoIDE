#include "Arduino.h"

#include "pid.h"
#include "state.h"
#include "config.h"

#define PWMH 5
#define PWML 6
#define PHASE 7
#define SR 4

float PIDController::update(float target) {
  unsigned long long time_now = millis();
  float dt = (time_now - time_prev) / 1000.;
  time_prev = time_now;

  // ピン割込みでcounterが壊れるかもしれないので
  noInterrupts();
  float current_value;
  if(pcfg.mode == PID_POSITION)
    current_value = (float)counter / cfg.encoder_resolution;
  else if(pcfg.mode == PID_VELOCITY)
    current_value = (float)(enc_prev - counter) / cfg.encoder_resolution / dt;
  enc_prev = counter;
  interrupts();

  float e = target - current_value;
  float P = e;
  I += e*dt;
  float D = (e - prev_e)/dt;
  prev_e = e;

  return P*pcfg.Kp + I*pcfg.Ki + D*pcfg.Kd;
}

