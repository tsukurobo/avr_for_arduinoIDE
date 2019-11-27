#define PIN_BRAKE 3
#define PIN_PID 2
#define PIN_I2C_A 1
#define PIN_I2C_B 0

#include "global.h"

void read_dip() {
  // pin table for i2c address pin:
  // | PIN_I2C_A(3) | PIN_I2C_B(4) | I2C mode |
  // |==============|==============|==========|
  // | 0            | 0            | PRESET   |
  // | 0            | 1            | ADDR1    |
  // | 1            | 0            | ADDR2    |
  // | 1            | 1            | X (TEST) |
  bool pin_i2c[2] = {digitalRead(PIN_I2C_A) == HIGH,
                     digitalRead(PIN_I2C_B) == HIGH};
  if(pin_i2c[0] && pin_i2c[1]) {
    is_test = true;
    return;
  }
  else if(pin_i2c[0]) i2c_addr_mode = I2C_ADDR1;
  else if(pin_i2c[1]) i2c_addr_mode = I2C_ADDR2;
  else i2c_addr_mode = I2C_PRESET;

  is_brake = digitalRead(PIN_BRAKE) == HIGH;
  is_pid = digitalRead(PIN_PID) == HIGH;
}

