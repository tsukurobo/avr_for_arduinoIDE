#include <Wire.h>

#include "imd.h"

void IseMotorDriver::set_power(int8_t power) {
  Wire.beginTransmission(addr);
  Wire.write(power);
  Wire.endTransmission();
}

int64_t IseMotorDriver::get_encoder() {
  Wire.requestFrom(addr, 4);
  union {
    byte b[4];
    int64_t i;
  } conv;
  for(int i=0; i<4; i++) conv.b[i] = Wire.read();
  return conv.i;
}

