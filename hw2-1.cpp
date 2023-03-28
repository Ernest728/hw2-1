#include "mbed.h"
PwmOut PWM1(D6);
// main() runs in its own thread in the OS
int main()
{
    PWM1.period_ms(5);
    float R[20];
    int Re[20];
    int i = 0;
    R[i++] = 0;
    for (; i < 5; i++)
        R[i] = i/5.0;
    for (;i < 10; i++)
        R[i] = 1.0;
    for (;i < 15; i++)
        R[i] = 1.0 - (i-10)/5.0;
    for (;i < 20; i++)
        R[i] = 0.0;
    for (i = 0; i < 20; i++)
        Re[i] = int(R[i]*5000);
    while (true) {
        for (int j = 0; j < 20; j++) {
            PWM1.pulsewidth_us(Re[j]);
            ThisThread::sleep_for(50ms);
        }
    }
}
