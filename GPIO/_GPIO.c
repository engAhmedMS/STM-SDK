#include "_GPIO.h"
void _GPIO_ENABLE_CLK(uint32_t GPIO_PORT) {
	if (GPIO_PORT == GPIO_PORT_A) {
		set_bit_Add((RCC_BASE + RCC_APB2ENR), 2);
	} else if (GPIO_PORT == GPIO_PORT_B) {
		set_bit_Add((RCC_BASE + RCC_APB2ENR), 3);
	} else if (GPIO_PORT == GPIO_PORT_C) {
		set_bit_Add((RCC_BASE + RCC_APB2ENR), 4);
	}
}
void _GPIO_DISABLE_CLK(uint32_t GPIO_PORT) {
	if (GPIO_PORT == GPIO_PORT_A) {
		clr_bit_Add((RCC_BASE + RCC_APB2ENR), 2);
	} else if (GPIO_PORT == GPIO_PORT_B) {
		clr_bit_Add((RCC_BASE + RCC_APB2ENR), 3);
	} else if (GPIO_PORT == GPIO_PORT_C) {
		clr_bit_Add((RCC_BASE + RCC_APB2ENR), 4);
	}
}
void _GPIO_LOCK_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN){
	GPIO_PORT += 0x18;
	set_bit_Add(GPIO_PORT, GPIO_PIN);
}
void _GPIO_RESET_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN){
	GPIO_PORT += 0x14;
	set_bit_Add(GPIO_PORT, GPIO_PIN);
}
void _GPIO_SET_MODE(uint32_t GPIO_PORT, uint8_t GPIO_PIN, uint8_t MODE, uint8_t CONFIG) {
	uint8_t RealPin = GPIO_PIN;
	if (GPIO_PIN > 7) {
		GPIO_PIN -= 8;
		GPIO_PORT += 0x04;
	}
	*((uint32_t*) GPIO_PORT) &= ~((0b1111) << (GPIO_PIN * 4));
	if (CONFIG == GPIO_IN_PULLUP) {
		*((uint32_t*) GPIO_PORT) |= (((GPIO_IN_PULLDOWN << 2)) << (GPIO_PIN * 4));
		_GPIO_WRITE_PIN(GPIO_PORT, RealPin, HIGH);
	}
	else if(CONFIG == GPIO_IN_PULLDOWN){
		*((uint32_t*) GPIO_PORT) |= (((GPIO_IN_PULLDOWN << 2)) << (GPIO_PIN * 4));
		_GPIO_WRITE_PIN(GPIO_PORT, RealPin, LOW);
	}
	else {
		*((uint32_t*) GPIO_PORT) |= (((CONFIG << 2) + MODE) << (GPIO_PIN * 4));
	}
}
void _GPIO_WRITE_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN, uint8_t STATE) {
	GPIO_PORT += 0x0C;
	if (STATE == HIGH) {
		*((uint32_t*) GPIO_PORT) |= (1 << GPIO_PIN);
	} else {
		*((uint32_t*) GPIO_PORT) &= ~(1 << GPIO_PIN);
	}
}
uint8_t _GPIO_READ_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN){
	GPIO_PORT += 0x08;
	return get_bit_Add(GPIO_PORT, GPIO_PIN);
}
