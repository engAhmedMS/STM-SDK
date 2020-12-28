#include <stdlib.h>
#include "stm32f10x.h"
#include "ADC.h"
#include "usart1.h"

void GPIO_SET_A0()
{
	// set PA0 as input in analog mode
	GPIOA->CRL &=~(GPIO_CRL_MODE0_0 | GPIO_CRL_MODE0_1 | GPIO_CRL_CNF0_0 | GPIO_CRL_CNF0_1);
}


int main(void)
{
	// Initialize system timer for 1µs ticks
	SysTick_Config(SystemCoreClock / 1000000UL);
	init_USART1();
	GPIO_SET_A0();

	init_ADC1();
	char adc_result_str[5];
	int result;
	while (1)
	{
		// perform ADC and convert result into C-string
		result  = readADC(0);
		itoa(result, adc_result_str, 10);
		// transmit result via serial port
		//USART1_transmitString(adc_result_str);
		//USART1_transmit('\n');
		 USART1_transmit(result);
		 delayms(100);

	}
	return 0;
}
