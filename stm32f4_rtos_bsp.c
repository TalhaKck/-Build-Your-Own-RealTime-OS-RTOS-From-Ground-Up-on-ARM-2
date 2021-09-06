/* Include Header files. */
#include "stm32f4_rtos_bsp.h" 

#define BSP_LED_PORT			  			 GPIOD
#define BSP_LED_GREEN							(1U<<12)
#define BSP_LED_ORANGE		  			(1U<<13)
#define BSP_LED_RED				  			(1U<<14)
#define BSP_LED_BLUE							(1U<<15)

/* Set the clock bits of the ports. */
#define GPIOA_CLOCK								(1U<<0)
#define GPIOC_CLOCK   						(1U<<2)
#define GPIOD_CLOCK								(1U<<3)
/* Set the mode bits of the ports. */
#define BSP_LED_GREEN_MODE_BIT		(1U<<24)
#define BSP_LED_ORANGE_MODE_BIT		(1U<<26)
#define BSP_LED_RED_MODE_BIT			(1U<<28)
#define BSP_LED_BLUE_MODE_BIT			(1U<<30)

#define BSP_BUTTON_PORT						 GPIOA
#define BSP_PROBE_PORT						 GPIOC

/* PC0 as output. */
#define BSP_Probe0_BIT  (1U<<0)  
/* PC1 as output. */
#define BSP_Probe1_BIT  (1U<<2)   
/* PC2 as output. */
#define BSP_Probe2_BIT  (1U<<4)   
/* PC4 as output. */
#define BSP_Probe3_BIT  (1U<<8)   

#define CH0							(1U<<0)
#define CH1							(1U<<1)
#define CH2							(1U<<2)
#define CH3							(1U<<4)

/**
  * @brief Function to initialize Probe. 
	*	@params void 
	*	@return non
  */
void bspProbeInit(void){

	  RCC->AHB1ENR |= GPIOC_CLOCK;
	  BSP_PROBE_PORT->MODER |=  BSP_Probe0_BIT|BSP_Probe1_BIT|BSP_Probe2_BIT|BSP_Probe3_BIT;
}
/**
  * @brief Function to initialize Probe Channel 0. 
	*	@params void 
	*	@return non
  */
void bspProbeCH0(){
  BSP_PROBE_PORT->ODR ^= CH0;
}
/**
  * @brief Function to initialize Probe Channel 1. 
	*	@params void 
	*	@return non
  */
void bspProbeCH1(){
  BSP_PROBE_PORT->ODR ^= CH1;
}
/**
  * @brief Function to initialize Probe Channel 2. 
	*	@params void 
	*	@return non
  */
void bspProbeCH2(){
  BSP_PROBE_PORT->ODR ^= CH2;
}
/**
  * @brief Function to initialize Probe Channel 3. 
	*	@params void 
	*	@return non
  */
void bspProbeCH3(){
  BSP_PROBE_PORT->ODR ^= CH3;
}

/**
  * @brief Function to initialize button. 
	*	@params void 
	*	@return non
  */
void bspButtonInit(void)
{
	/* Enable required clock. */
	RCC->AHB1ENR |= GPIOA_CLOCK;
	/* Clear PA0 pin. */
	BSP_BUTTON_PORT->MODER &= ~0x00000011;
}
/**
  * @brief Function to read button. 
	*	@params void 
	*	@return IDR value
  */
uint32_t bspButtonRead(void)
{
	/* Return Input data register.*/
	return BSP_BUTTON_PORT->IDR &0x01;
}
/**
  * @brief Function to make delay. 
	*	@params uint32_t delay 
	*	@return non
  */
void bspDelayMillis(uint32_t delay)
{
	/* Enable TIM3 clock. */
	RCC->APB1ENR |= 0x02;
	/* 16MHz - 1, count from zero. 16MHz / 160 = 100KHz */
	TIM3->PSC = 160-1; 
	/* 100KHz / 100 = 1000 */
	TIM3->ARR = 100 - 1; 
	TIM3->CNT = 0;
	TIM3->CR1 = 1;
	for(uint32_t i = 0; i<delay; i++)
	{
		/* Wait for Update interrupt flag(UIF) set. */
		while(!(TIM3->SR & 1)) 
		{
		}
		/* Reset the status register 1. */
		TIM3->SR &= ~1;
	}
}
/**
  * @brief Function to initialize ADC1. 
	*	@params void 
	*	@return non
  */
void bspAdc1Init(void)
{
	/* Gpio pin. */
	RCC->AHB1ENR |= 1;
	/* PA1 set as analog. */
	GPIOA->MODER |= 0xC;
	
	/* Enable ADC1 clock. */
	RCC->APB2ENR |= 0x00000100; 
	ADC1->CR2 = 0;
	/* Conversion sequence start at channel 1. */
	ADC1->SQR3 = 1; 
	/* Length of sequence is 1. */
	ADC1->SQR1 = 0; 
	ADC1->CR2 |= 1;
}
/**
  * @brief Function to read ADC1. 
	*	@params void 
	*	@return data register value
  */
uint32_t bspAdcRead(void)
{
	/* Start conversion. */
	ADC1->CR2 |= 0x40000000;
	/* Wait for conversion complete. */
	while(!(ADC1->SR & 2))
	{
	}
	/* Return data register value. */
	return ADC1->DR;
}
/**
  * @brief Function to initialize board leds. 
	*	@params void 
	*	@return non
  */
void bspLedInit(void)
{
	__disable_irq();
	/* Set the bus clock enable. */
	RCC->AHB1ENR |= GPIOD_CLOCK;
	GPIOD->MODER |= BSP_LED_RED_MODE_BIT|BSP_LED_BLUE_MODE_BIT|BSP_LED_GREEN_MODE_BIT|BSP_LED_ORANGE_MODE_BIT;
	__enable_irq();
	
}
/**
  * @brief Function to initialize green led. 
	*	@params void 
	*	@return non
  */
void bspLedGreenOn(void)
{
	GPIOD->ODR |= BSP_LED_GREEN;
}
/**
  * @brief Function to off green led. 
	*	@params void 
	*	@return non
  */
void bspLedGreenOff(void)
{
	GPIOD->ODR &= ~BSP_LED_GREEN;
}
/**
  * @brief Function to toggle green led. 
	*	@params void 
	*	@return non
  */
void bspLedGreenToggle(void)
{
	GPIOD->ODR ^= BSP_LED_GREEN;
}
/**
  * @brief Function to initialize orange led. 
	*	@params void 
	*	@return non
  */
void bspLedOrangeOn(void)
{
	GPIOD->ODR |= BSP_LED_ORANGE;
}
/**
  * @brief Function to off orange led. 
	*	@params void 
	*	@return non
  */
void bspLedOrangeOff(void)
{
	GPIOD->ODR &= ~BSP_LED_ORANGE;
}
/**
  * @brief Function to toggle orange led. 
	*	@params void 
	*	@return non
  */
void bspLedOrangeToggle(void)
{
	GPIOD->ODR ^= BSP_LED_ORANGE;
}
/**
  * @brief Function to initialize red led. 
	*	@params void 
	*	@return non
  */
void bspLedRedOn(void)
{
	GPIOD->ODR |= BSP_LED_RED;
}
/**
  * @brief Function to off red led. 
	*	@params void 
	*	@return non
  */
void bspLedRedOff(void)
{
	GPIOD->ODR &= ~BSP_LED_RED;
}
/**
  * @brief Function to toggle red led. 
	*	@params void 
	*	@return non
  */
void bspLedRedToggle(void)
{
	GPIOD->ODR ^= BSP_LED_RED;
}
/**
  * @brief Function to initialize blue led. 
	*	@params void 
	*	@return non
  */
void bspLedBlueOn(void)
{
	GPIOD->ODR |= BSP_LED_BLUE;
}
/**
  * @brief Function to off blue led. 
	*	@params void 
	*	@return non
  */
void bspLedBlueOff(void)
{
	GPIOD->ODR &= ~BSP_LED_BLUE;
}
/**
  * @brief Function to toggle blue led. 
	*	@params void 
	*	@return non
  */
void bspLedBlueToggle(void)
{
	GPIOD->ODR ^= BSP_LED_BLUE;
}
