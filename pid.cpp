#include "Arduino.h"

#include "pid.h"
#include "state.h"
#include "config.h"

#define PWMH 5
#define PWML 6
#define PHASE 7
#define SR 4

PIDController::PIDController(float Kp, float Ki, float Kd, Config& cfg) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->I = 0;
  this->prev_e = 0;
  this->enc_prev = 0;
  this->time_prev = millis();
  this->cfg = cfg;
}

float PIDController::update(float target) {
  unsigned long long time_now = millis();
  float dt = (time_now - time_prev) / 1000.;
  time_prev = time_now;

  float current_value;
  if(cfg.pid_mode == PID_POSITION)
    current_value = (float)counter / cfg.encoder_resolution;
  else if(cfg.pid_mode == PID_VELOCITY)
    current_value = (float)(enc_prev - counter) / cfg.encoder_resolution / dt;
  enc_prev = counter;

  float e = target - current_value;
  float P = e;
  I += e*dt;
  float D = (e - prev_e)/dt;
  prev_e = e;

  return P*Kp + I*Ki + D*Kd;
}

