#ifndef __STM32_RTOS_BSP_H__
#define __STM32_RTOS_BSP_H__
#include "stm32f4xx.h"                  // Device header
#include "stdint.h"

/** @brief:

 *  The meaning of each digit of application version:
 *  First digit:    Major release version.
 *  Second digit:   Minor release version.
 *  Third digit:    Hotfix/Bugfix version.
 *  Fourth digit:   Feature version.
 *
 * */
#define APPLICATION_VERSION   "v0.0.0.2"

/**
  * @brief Function to make delay. 
	*	@params uint32_t delay 
	*	@return non
  */
void bspDelayMillis(uint32_t delay);
	
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

/**
  * @brief Function to read ADC1. 
	*	@params void 
	*	@return data register value
  */
uint32_t bspAdcRead(void);
/**
  * @brief Function to initialize button. 
	*	@params void 
	*	@return non
  */
void bspButtonInit(void);
/**
  * @brief Function to read button. 
	*	@params void 
	*	@return IDR value
  */
uint32_t bspButtonRead(void);
#endif
