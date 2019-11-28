#include<Arduino.h>

#define PWMH 5
#define PWML 6
#define PHASE 7
#define SR 4

#define ANALOG_WRITE_MAX 255

void drive(int duty){

  //dutyの値の正負でモータのcw ccwを切り替える
	if(duty>=0)digitalWrite(PHASE, LOW);
	else digitalWrite(PHASE, HIGH);

	int pw = (int)((float)ANALOG_WRITE_MAX/100*abs(duty));

	analogWrite(PWML, pw);//モードラにｐｗｍを出力
	analogWrite(PWMH, pw);

}

