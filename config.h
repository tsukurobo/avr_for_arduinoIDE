#ifndef IMD_CONFIG_H
#define IMD_CONFIG_H

#include "Arduino.h"

typedef enum PIDMode {
  PID_POSITION,
  PID_VELOCITY,
} PIDMode;

class Config {
  public:
    Config();
    Config(uint8_t i2c_preset, int encoder_resolution);

    // 将来的にはread_from_i2cも実装…？
    void read_from_dip();

    bool is_pid, is_brake, is_test;
    PIDMode pid_mode;
    uint8_t i2c_addr;
    int encoder_resolution;
};

#endif

