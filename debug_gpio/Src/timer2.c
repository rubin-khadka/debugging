#include "stm32f103xb.h"
#include "timer2.h"

void TIMER2_Init(void)
{
    // Enable TIM2 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Small delay for clock to stabilize (TIM2 is on APB1)
    for(volatile int i = 0; i < 10; i++);

    TIM2->PSC = 7200 - 1;

    TIM2->DIER &= ~TIM_DIER_UIE;

}

void TIMER2_Delay_ms(uint32_t ms)  // Changed to uint32_t
{
    if (ms == 0) return;

    // Stop timer to reconfigure
    TIM2->CR1 &= ~TIM_CR1_CEN;

    TIM2->ARR = (uint32_t)ms - 1;  // FIXED: was (ms-1)*10

    // Reset counter
    TIM2->CNT = 0;

    // Clear any pending update flag
    TIM2->SR &= ~TIM_SR_UIF;

    // Start timer
    TIM2->CR1 |= TIM_CR1_CEN;

    // Wait for update event (counter reached ARR)
    while (!(TIM2->SR & TIM_SR_UIF));

    // Clear update flag
    TIM2->SR &= ~TIM_SR_UIF;

    // Stop timer (optional — saves power)
    TIM2->CR1 &= ~TIM_CR1_CEN;
}
