/*
 * traffic_light.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#include "traffic_light.h"

uint16_t WALKERCLIGHT [2]= {WALKER_LIGHT_0_Pin, WALKER_LIGHT_1_Pin};


// Red mean light 0 off, light 1 off
// Green mean light 0 off, light 1 on
// Amber mean light 0 on, light 1 on
void setTrafficLightDefault(int lane){
	switch(lane){
	case 0:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin, RESET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin, RESET);
		HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_0_Pin, RESET);
		HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin, RESET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_1_Pin, RESET);
		HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin, RESET);
		break;
	default:
		break;
	}

}

void setGreen(int lane){
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
	case 2:
		HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_0_Pin, RESET);
		HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin, SET);
		break;
	default:

		break;

	}
}

void setRed(int lane){
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
	case 2:
		HAL_GPIO_WritePin(WALKER_LIGHT_0_GPIO_Port, WALKER_LIGHT_0_Pin, SET);
		HAL_GPIO_WritePin(WALKER_LIGHT_1_GPIO_Port, WALKER_LIGHT_1_Pin, RESET);
		break;
	default:

		break;

	}
}

void setAmber(int lane){
	switch (lane) {
	case 0:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin,
				SET);
		break;
	case 1:
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin,
				SET);
		HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin,
				SET);
		break;

	default:

		break;

	}
}



