#ifndef ADC_H__
#define ADC_H__
#include "stm32f10x.h"

void delay(int time);
void delayms(int time);
void init_ADC1();
int readADC(uint8_t channel);








#endif
