/**
 * @file           : main.c
 * @author         : Rubin Khadka
 * @brief          : Main program body
 */

#include "stm32f103xb.h"
#include "gpio.h"

int main(void) {
	// GPIO PC13 initialization
	LED_init();

	while (1) {
		LED_ON();
		Delay_ms(500);
		LED_OFF();
		Delay_ms(500);
	}
}
