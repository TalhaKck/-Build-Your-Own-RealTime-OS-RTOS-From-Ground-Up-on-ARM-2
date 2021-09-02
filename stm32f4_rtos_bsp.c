/* Include Header files. */
#include "stm32f4_rtos_bsp.h"

#define BSP_LED_PORT			  		 GPIOD
#define BSP_LED_GREEN						(1U<<12)
#define BSP_LED_ORANGE		  		(1U<<13)
#define BSP_LED_RED				  		(1U<<14)
#define BSP_LED_BLUE						(1U<<15)

/* Set the clock bits of the ports. */
#define GPIOD_CLOCK							(1U<<3)

#define BSP_LED_GREEN_MODE_BIT		(1U<<24)
#define BSP_LED_ORANGE_MODE_BIT		(1U<<26)
#define BSP_LED_RED_MODE_BIT			(1U<<28)
#define BSP_LED_BLUE_MODE_BIT			(1U<<30)

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
	*	@return non
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
