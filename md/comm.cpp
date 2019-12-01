#include <Wire.h>

#include "comm.h"
#include "state.h"

// TODO: make this function portable
void write_counter() {
  union {
    byte b[4];
    int64_t i;
  } conv;
  conv.i = counter;
  Wire.write(conv.b, 4);
}

void read_power() {
  power = Wire.read();
}

void recv_handler(int numBytes) {
  read_power();
}

void set_wire_callback() {
  Wire.onRequest(write_counter);
  Wire.onReceive(recv_handler);
}
