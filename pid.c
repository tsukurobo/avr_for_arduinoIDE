#include "pid.h"
int pid(double target, long int counter, int mode){



	double now_state = 0;

	enc  = (double)counter;

	if(mode == POSITION){

		now_state = enc * 360 / resolution_enc ;//エンコーダの値から角度[度]を計算
	

	}
	else if(mode == VELOCITY){

		now_state = (enc - preenc)/ resolution_enc /dt *60;//エンコーダの値から速度[rpm]を計算

		preenc = enc;
	

	}


	P = target - now_state;
    
	I += P*dt;
    
	D = (P - preP)/dt;
    
	duty = Kp * P + Ki * I + Kd * D;
    
	preP = P;
    
	if(duty > max_duty) duty = max_duty;//dutyの上限下限を設定
	if(duty < min_duty) duty = min_duty;
    
	return duty;
}


