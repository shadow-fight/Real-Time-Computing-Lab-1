#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "list.h"
#include "portable.h"
#include "board_led.h"
#include "board_buttons.h"


#include <stdio.h>
#include "MKW41Z4.h"

void ledtask1 ()
	{
		while(1)
		{
			LED_On(1);
			vTaskDelay(portTICK_PERIOD_MS*200);
			LED_Off(1);
			vTaskDelay(portTICK_PERIOD_MS*200);
		}
	}
	
	void ledtask2 ()
	{
		while(1)
		{
			LED_On(3);
			vTaskDelay(portTICK_PERIOD_MS*150);
			LED_Off(3);
			vTaskDelay(portTICK_PERIOD_MS*150);
		}
	}
	
//--------------------------------------------------------------------

int main(void)
	{
		LED_Initialize();
		xTaskCreate(ledtask1,"Blue_LED1",configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);	
		xTaskCreate(ledtask2,"Red_LED3",configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);	

		vTaskStartScheduler();
		
		while(1);
	}
//--------------------------------------------------------------------


	//----------------------------------------------------------------
