/**
 * @file           : main.c
 * @author         : Rubin Khadka
 * @brief          : Main program body
 */

#include "stm32f103xb.h"
#include "gpio.h"
#include "timer2.h"

int main(void) {
	// GPIO PC13 initialization
	LED_init();

	while (1) {
		LED_ON();
		TIMER2_Delay_ms(500);
		LED_OFF();
		TIMER2_Delay_ms(500);
	}
}
