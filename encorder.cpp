#include "ti2c_slave.h"
#include "global.h"

//エンコーダのＡＢ層の立ち上がりを見てカウントダウンカウントアップする
//Ａ層　２５ピン　Ｂ層　２４ピン

ISR(PCINT1_vect,ISR_NOBLOCK){

  if((PINC & (1<<PINC0))^((PINC & (1<<PINC1))>>1))--counter;
  else ++counter;

}


//エンコーダの値をマスターに返す
void send_enc(){

  char buf[10] = {};
  int num;
  num = sprintf(buf, "%d$", counter);

  //receiver.sendStr(buf);	

}


