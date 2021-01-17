#ifndef _GPIO_H
#define _GPIO_H

#include "GPIO_CMD.h"
#include "RCC_TMP.h"
#include "GPIO_PORTS.h"
#include "GPIO_STATE.h"
#include "bit_configurations.h"
#include <inttypes.h>

void _GPIO_ENABLE_CLK(uint32_t GPIO_PORT);
void _GPIO_DISABLE_CLK(uint32_t GPIO_PORT);
void _GPIO_LOCK_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN);
void _GPIO_RESET_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN);
void _GPIO_SET_MODE(uint32_t GPIO_PORT, uint8_t GPIO_PIN, uint8_t MODE, uint8_t CONFIG);
void _GPIO_WRITE_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN, uint8_t STATE);
uint8_t _GPIO_READ_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN);

#endif
