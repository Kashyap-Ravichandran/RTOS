# RTOS

Note : The code was developed for FRDM KL128Z microcontroller running ARM's cortex M0+ processor. Further more, a shield was developed for the FRDM board which communicates to a LCD touch diplay using the GPIO port and a high brightness LED to which the power is delivered by a switch mode power supply. The LED is made to blink by providing the switch mode power supply an fluctuating DC. This is delivered by the onboard PMW module. A feedback is also given back to the microcontroller through thr ADC. Using this converted value the processor adjusts the period PWM wave. 
