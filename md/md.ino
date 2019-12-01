#include <Wire.h>

#include "pid.h"
#include "comm.h"
#include "state.h"
#include "config.h"
#include "driver.h"

#define SR 4
#define PWMH 5
#define PWML 6
#define PHASE 7

// TODO: clean up everything
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
  set_wire_callback();

  long long t_prev = millis();
  if(!cfg.is_test) {
    while(true) {
      if(abs(millis() - t_prev) > 1) {
        t_prev = millis();

        int8_t raw_power = power;
        if(cfg.is_pid) raw_power = pid.update(pid_target);
        drive(raw_power, cfg);
      }
    }
  }
}

void loop() {
}

ISR(PCINT1_vect,ISR_NOBLOCK){
  if((PINC & (1<<PINC0))^((PINC & (1<<PINC1))>>1))--counter;
  else ++counter;
}

