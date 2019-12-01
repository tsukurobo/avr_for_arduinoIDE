#ifndef IMD_IMD_H
#define IMD_IMD_H

#include <Arduino.h>

class IseMotorDriver {
  public:
    IseMotorDriver(int8_t addr) : addr(addr) {};
    void set_power(int8_t power);
    int64_t get_encoder();

  private:
    int8_t addr;
};

#endif

