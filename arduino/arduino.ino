#include <Wire.h>

#include "imd.h"

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

IseMotorDriver imd(0x22);
int diff = 1;
int power = 0;
void loop() {
  // sample
  if(abs(power) == 100) diff *= -1;
  power += diff;
  imd.set_power(power);
  char text[10];
  sprintf(text, "%lld", imd.get_encoder());
  Serial.println(text);
}

