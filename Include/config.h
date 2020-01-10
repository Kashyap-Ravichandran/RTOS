#ifndef CONFIG_H
#define CONFIG_H

// Base code works if only one option is enabled
#define USE_ADC_FOR_BUCK 1
#define USE_ADC_FOR_TOUCHSCREEN 1
#define use_refresh 1
extern volatile int queue_Iset[480], queue_Imeasured[480], front, end, size,number_elements;

void push(int, int);
int pop(int, int a[]);


#endif // CONFIG_H
