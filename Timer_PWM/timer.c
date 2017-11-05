











#include "timer.h"

#include "timer_driver.h"





int main(void){

	/*RCC->AHB1ENR |= (1<<RCC_APB1ENR_TIM2EN); 				//Enable clock for timer
	TIM2->CR1 |= TIM_CR1_CEN;												//Enable timer2
	TIM2->PSC = 10000;															//Set prescaler
	TIM2->ARR = 1000;																//Set Auto reload register value
	TIM2->CR1 |= (1<<TIM_CR1_DIR);								  //this is for down counting mode//Set counter mode up/down default is up counter
	/ *for CR1 CEN and DIR bit can be set in a single statement as>> TIM2->CR1 |= TIM_CR1_CEN | TIM_CR1_DIR ;*/
	/*for centre aligned mode use CMS bits
	
	
	*/
																									//Set timer period
																									//set clock division
																									//start counting by enabling CEN in CR1 register*/
	uint32_t high_speed;
	high_speed = 0x03;
	
	RCC->APB2ENR |= (1<<0);  			//Enable clock for timer1
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	GPIOE->MODER  = (ALT_FUN_MODE << (2*14));	
	GPIOE->OSPEEDR |=(high_speed<<28);
	GPIOE->AFR[1] = (GPIO_AF1_TIM1 << 24);
	
	TIM1->PSC = 15;
	TIM1->ARR = 999;
	TIM1->CCR4 = 490;
	TIM1->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4FE;        //o/p compare 4 mode in PWM mode 1 last is o/p compare fast enable
	TIM1->CCER |= TIM_CCER_CC4E;																								//output enable for channel 4
  TIM1->BDTR |= TIM_BDTR_MOE;																																																			
	TIM1->CR1 |= TIM_CR1_CEN;																										//Enable timer1
	TIM1->EGR |= TIM_EGR_UG;																										//Update generation

	
	while(1)
	{
																									//TIM2->CNT
	}
	
	
	
	
	
	
	
	
	
	
	

}