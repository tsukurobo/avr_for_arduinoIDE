#include <Wire.h>

#include "pid.h"
#include "state.h"
#include "config.h"

void setup() {
  // i2cは 0x0a 〜 0x77 の値を推奨, 0x80以上は多分プロトコル的に動かない
  // Config(i2c_addr, encoder_resolution)
  Config cfg = Config(0x22, 4096);
  cfg.read_from_dip();

  PIDController pid = PIDController(4.05516, 0.21958, 0.00059, cfg);

  PORTC &= ~(1<<PINC0 | 1<<PINC1);

  Wire.begin(cfg.i2c_addr);
}

void loop() {
}

ISR(PCINT1_vect,ISR_NOBLOCK){
  if((PINC & (1<<PINC0))^((PINC & (1<<PINC1))>>1))--counter;
  else ++counter;
}

