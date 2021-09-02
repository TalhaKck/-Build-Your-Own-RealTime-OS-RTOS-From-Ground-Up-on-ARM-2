/* Include Header files. */
#include "stm32f4_rtos_bsp.h"


int main()
{
	/* Holds delay variable. */
	int i; 
	/* Holds ADC value. */
	uint32_t sensorVal = 0;
	/* Initialize led configs. */
	bspLedInit();
	/* Initialize ADC configs. */
	bspAdc1Init();
	/* Main loop. */
	while(1)
	{
		//bspLedGreenToggle();
		bspLedGreenOn();
		bspLedRedOn();
		for(i = 0; i < 50000000; i++);
		bspLedGreenOff();
		bspLedRedOff();
		for(i = 0; i < 50000000; i++);
		sensorVal = bspAdcRead();
	}
}
