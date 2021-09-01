#ifndef __STM32_RTOS_BSP_H__
#define __STM32_RTOS_BSP_H__
#include "stm32f4xx.h"                  // Device header


/**
  * @brief Function to initialize board leds. 
	*	@params void 
	*	@return non
  */
void bspLedInit(void);

/**
  * @brief Function to initialize green led. 
	*	@params void 
	*	@return non
  */
void bspLedGreenOn(void);
/**
  * @brief Function to off green led. 
	*	@params void 
	*	@return non
  */
void bspLedGreenOff(void);

/**
  * @brief Function to toggle green led. 
	*	@params void 
	*	@return non
  */
void bspLedGreenToggle(void);

/**
  * @brief Function to initialize orange led. 
	*	@params void 
	*	@return non
  */
void bspLedOrangeOn(void);

/**
  * @brief Function to off orange led. 
	*	@params void 
	*	@return non
  */
void bspLedOrangeOff(void);

/**
  * @brief Function to toggle orange led. 
	*	@params void 
	*	@return non
  */
void bspLedOrangeToggle(void);

/**
  * @brief Function to initialize red led. 
	*	@params void 
	*	@return non
  */
void bspLedRedOn(void);
	
/**
  * @brief Function to off red led. 
	*	@params void 
	*	@return non
  */
void bspLedRedOff(void);

/**
  * @brief Function to toggle red led. 
	*	@params void 
	*	@return non
  */
void bspLedRedToggle(void);

/**
  * @brief Function to initialize blue led. 
	*	@params void 
	*	@return non
  */
void bspLedBlueOn(void);

/**
  * @brief Function to off blue led. 
	*	@params void 
	*	@return non
  */
void bspLedBlueOff(void);

/**
  * @brief Function to toggle blue led. 
	*	@params void 
	*	@return non
  */
void bspLedBlueToggle(void);

/**
  * @brief Function to initialize ADC1. 
	*	@params void 
	*	@return non
  */
void bspAdc1Init(void);
#endif
