#include "Arduino.h"

#include "global.h"

bool is_pid = false;
bool is_brake = false;
bool is_test = false;

long int counter = 0;

I2CAddrMode i2c_addr_mode = I2C_PRESET;
PIDMode pid_mode = PID_POSITION;
