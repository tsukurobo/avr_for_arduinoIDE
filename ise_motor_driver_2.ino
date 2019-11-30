#include <Wire.h>

#include "pid.h"
#include "state.h"
#include "config.h"
#include "driver.h"

#define SR 4
#define PWMH 5
#define PWML 6
#define PHASE 7

void setup() {
  // i2cは 0x0a 〜 0x77 の値を推奨, 0x80以上は多分プロトコル的に動かない
  // Config(i2c_addr, encoder_resolution)
  Config cfg = Config(0x22, 4096);
  cfg.read_from_dip();

  PIDConfig pcfg = PIDConfig(1, 1, 1, PID_VELOCITY);
  PIDController pid = PIDController(cfg, pcfg);

  PORTC &= ~(1<<PINC0 | 1<<PINC1);
  pinMode(SR, OUTPUT);
  pinMode(PWMH, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(PHASE, OUTPUT);

  Wire.begin(cfg.i2c_addr);

  long long t_prev = millis();
  if(!cfg.is_test) {
    if(abs(millis() - t_prev) > 1) {
      t_prev = millis();
      if(cfg.is_pid) pid.update(pid_target);
      drive(power, cfg);
    }
  }
}

void loop() {
}

ISR(PCINT1_vect,ISR_NOBLOCK){
  if((PINC & (1<<PINC0))^((PINC & (1<<PINC1))>>1))--counter;
  else ++counter;
}

