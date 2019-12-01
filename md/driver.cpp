#include<Arduino.h>

#include "driver.h"

#define SR 4
#define PWMH 5
#define PWML 6
#define PHASE 7

#define ANALOG_WRITE_MAX 255

void drive(int duty, Config cfg){
  if(cfg.is_brake) digitalWrite(SR, HIGH);
  else digitalWrite(SR, LOW);

  //dutyの値の正負でモータのcw ccwを切り替える
	if(duty>=0)digitalWrite(PHASE, LOW);
	else digitalWrite(PHASE, HIGH);

	int pw = (int)((float)ANALOG_WRITE_MAX/100*abs(duty));

	analogWrite(PWML, pw);//モードラにｐｗｍを出力
	analogWrite(PWMH, pw);

}

