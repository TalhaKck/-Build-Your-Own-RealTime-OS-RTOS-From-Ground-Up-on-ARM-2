/* Include Header files. */
#include "stm32f4_rtos_bsp.h"


int main()
{
	/* Holds ADC value. */
	uint32_t sensorVal = 0;
  /* Holds button state. */
	uint32_t buttonState = 0;
	/* Initialize led configs. */
	bspLedInit();
	/* Initialize ADC configs. */
	bspAdc1Init();
	/* Initialize button configs. */
	bspButtonInit();
	/* Main loop. */
	while(1)
	{
		//bspLedGreenToggle();
		bspLedGreenOn();
		bspLedRedOn();
		bspDelayMillis(1000);
		bspLedGreenOff();
		bspLedRedOff();
		bspDelayMillis(1000);
		//sensorVal = bspAdcRead();
		buttonState = bspButtonRead();
	}
}
