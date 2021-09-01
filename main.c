/* Include Header files. */
#include "stm32f4_rtos_bsp.h"


int main()
{
	/* Holds delay variable. */
	int i; 
	/* Initialize led configs. */
	bspLedInit();
	
	while(1)
	{
		bspLedGreenToggle();
		//bspLedGreenOn();
		bspLedRedOn();
		for(i = 0; i < 50000000; i++);
		//bspLedGreenOff();
		bspLedRedOff();
	}
}
