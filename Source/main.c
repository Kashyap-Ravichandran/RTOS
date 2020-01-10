/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>
#include <stdio.h>
#include "math.h"

#include "gpio_defs.h"

#include <cmsis_os2.h>
#include "threads.h"

#include "LCD.h"
#include "LCD_driver.h"
#include "font.h"

#include "LEDs.h"
#include "timers.h"
#include "sound.h"
#include "DMA.h"
#include "delay.h"
#include "profile.h"

#include "control.h"
#include <stdlib.h>

volatile CTL_MODE_E control_mode=DEF_CONTROL_MODE;

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void) {
	
	int i=0;
	int temp;
	PT_T p;
	
	Init_Debug_Signals();
	Init_RGB_LEDs();
	Control_RGB_LEDs(0,0,1);			
	
	Sound_Disable_Amp();
	
	LCD_Init();
	Control_RGB_LEDs(1,0,0);
	LCD_Text_Init(1);
	LCD_Erase();
	
	LCD_Erase();
	Control_RGB_LEDs(1,0,0);
	//LCD_Text_PrintStr_RC(0,0, "Test Code");
	LCD_Text_PrintStr_RC(0,5,"LOADING...");
	
	for(i=0;i<500;i++)
	{
				temp=(rand()%320)-10;
				p.X=rand()%240;
				p.Y=temp;
				LCD_Plot_Pixel(&p, &white);
				Delay(1);
	}
	Delay(1000);
	
	
#if 0
	// LCD_TS_Calibrate();
	LCD_TS_Test();
#endif
	Delay(70);
	LCD_Erase();

	Init_Buck_HBLED();
	
	osKernelInitialize();
	Create_OS_Objects();
	osKernelStart();	
}
