/*
 * traffic_light.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#include "traffic_light.h"

uint16_t WALKERCLIGHT [2]= {WALKER_LIGHT_0_Pin, WALKER_LIGHT_1_Pin};


// Red mean light 0 on, light 1 off
// Green mean light 0 off, light 1 on
// Amber mean light 0 on, light 1 on
void setTrafficLightDefault(int lane){
	switch(lane){
	case 0:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin, SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin, SET);
		HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_0_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin, SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin, SET);
		HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin, SET);
		break;
	default:
		break;
	}
	COUNTER[lane]= 0;
}

void setRed(int lane){
	switch (lane) {
	case 0:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin,
				RESET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin,
				SET);
		break;
	case 1:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin,
				RESET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin,
				SET);
		break;
	default:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin,
				SET);
		break;

	}
}

void setGreen(int lane){
	switch (lane) {
	case 0:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin,
				RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin,
				RESET);
		break;
	default:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin,
				SET);
		break;

	}
}

void setAmber(int lane){
	switch (lane) {
	case 0:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin,
				RESET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin,
				RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin,
				RESET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin,
				RESET);
		break;
	default:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin,
				SET);
		break;

	}
}

//void displaySEG(int bit, uint16_t type){
//	GPIO_TypeDef *GPIO = (bit >= 9)? GPIOB : GPIOA;
//	HAL_GPIO_WritePin(GPIO, BIT[bit], type);
//}

//void display7SEG(int type, int num){
//	switch(num){
//		case 0:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 1:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 2:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 3:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 4:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 5:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 6:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 7:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 8:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, SET);
//			break;
//		case 9:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, SET);
//			break;
//		default:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, SET);
//			break;
//	}
//}

