#include "config.h"

#define PIN_BRAKE 3
#define PIN_PID 2
#define PIN_I2C_A 1
#define PIN_I2C_B 0

// ArduinoIDEでコンパイルを通すためだけのコンストラクタ
// プログラムを書くときは呼ばないこと
Config::Config() {
}

Config::Config(uint8_t i2c_preset, int encoder_resolution) {
  this->i2c_addr = i2c_preset;
  this->encoder_resolution = encoder_resolution;
}

void Config::read_from_dip() {
  // pin table for i2c address pin:
  // | PIN_I2C_A(3) | PIN_I2C_B(4) | I2C addr |
  // |==============|==============|==========|
  // | 0            | 0            | preset   |
  // | 0            | 1            | 0x08     |
  // | 1            | 0            | 0x09     |
  // | 1            | 1            | X (TEST) |
  bool pin_i2c[2] = {digitalRead(PIN_I2C_A) == HIGH,
                     digitalRead(PIN_I2C_B) == HIGH};
  if(pin_i2c[0] && pin_i2c[1]) {
    is_test = true;
    return;
  }
  else if(pin_i2c[0]) i2c_addr = 0x08;
  else if(pin_i2c[1]) i2c_addr = 0x09;

  is_brake = digitalRead(PIN_BRAKE) == HIGH;
  is_pid = digitalRead(PIN_PID) == HIGH;
}
