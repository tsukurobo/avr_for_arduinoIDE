#define PWMH 5
#define PWML 6
#define dir 7
#define SR 4

#define max_duty 255
#define min_duty -255
#define POSITION 0
#define VELOCITY 1
#define resolution_enc 4048
#define dt 0.003

const float Kp=4.05516;
const float Ki=0.21958;
const float Kd=0.00059;

float P=0;
float preP=0;
float I=0;
float D=0;

float duty=0;
int pw = 0;

double enc = 0;
double preenc = 0;
