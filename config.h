#ifndef IMD_CONFIG_H
#define IMD_CONFIG_H

#include "Arduino.h"

typedef enum PIDMode {
  PID_POSITION,
  PID_VELOCITY,
} PIDMode;

class Config {
  public:
    Config(uint8_t i2c_addr, int encoder_resolution)
      : is_pid(false), is_brake(false), is_test(false),
        i2c_addr(i2c_addr), encoder_resolution(encoder_resolution) {};

    // 将来的にはread_from_i2cも実装…？
    // does not set encoder_resolution
    // does not set i2c_addr in some case
    void read_from_dip();

    bool is_pid, is_brake, is_test;
    uint8_t i2c_addr;
    int encoder_resolution;
};

#endif

