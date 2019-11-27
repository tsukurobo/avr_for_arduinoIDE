#include "driver.h"
#include<Arduino.h>


void driver_comand(int duty){

	int pw = 0;	

	if(duty>=0)digitalWrite(dir,LOW);//dutyの値の正負でモータのcw ccwを切り替える
	else digitalWrite(dir,HIGH);

	pw = abs(duty);

	analogWrite(PWML,pw);//モードラにｐｗｍを出力
	analogWrite(PWMH,pw);

}
