/*
 * Pedestrian.c
 *
 *  Created on: Dec 5, 2023
 *      Author: MY PC
 */
#include "pedestrian.h"



void buzzer(unsigned int freq){
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, freq);
}
