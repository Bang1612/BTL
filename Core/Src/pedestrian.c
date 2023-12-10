/*
 * Pedestrian.c
 *
 *  Created on: Dec 5, 2023
 *      Author: MY PC
 */
#include "pedestrian.h"

void ped_run(){

//	if (PEDESTRIAN_MODE) {
//		if (LED_STATE[0] == GREEN_STATE || LED_STATE[0] == YELLOW_STATE) {
////			HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_0_Pin,
////					RESET);
////			HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin,
////					SET);
//
////			traffic light is red
//		} else if (LED_STATE[0] == RED_STATE) {
//			HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_0_Pin,
//					SET);
//			HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin,
//					RESET);
//		} else {
//			HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_0_Pin,
//					SET);
//			HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin,
//					SET);
//		}
//	}

}

void buzzer(unsigned int freq){
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, freq);
}
