/*
 * ADC.h
 *
 * Created: 24/04/2015 02:56:24 م
 *  Author: Ahmed Abdelkader
 */ 

#ifndef ADC_H_
#define ADC_H_

#include "micro_config.h"
#include "std_types.h"

void ADC_init(void);
uint16 ADC_read(uint8 channel_num);

#endif /* ADC_H_ */