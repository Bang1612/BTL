/*
 * fsm_manual.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#include "fsm_manual.h"

int tempDuration = 0;

void changeMode(int mode){
	setTrafficLightDefault(0);
	setTrafficLightDefault(1);
	MODE = mode;
	setTimer(2, 25);
}

void displayDuration(int mode, int duration){
//	display7SEG(0, mode);
//	display7SEG(1, 0);
//	display7SEG(2, duration%10);
//	display7SEG(3, (int) (duration/10));
	Display(mode);
	Display(duration);
}
//handle manual setting
void fsm_manual_run(){

	switch(MODE){
		case MODE_1:
			fsm_automatic_run(0);
			fsm_automatic_run(1);
			ped_run();
			if (isButtonPressed(0) == 1){
				tempDuration = RED_DURATION;
				changeMode(MODE_2);
//				Turn off pedestrian mode
				PEDESTRIAN_MODE = 0;
				HAL_GPIO_WritePin(WALKER_BUZZER_GPIO_Port, WALKER_BUZZER_Pin, RESET);
			}
//			Change light on
			if(isButtonPressed(1) == 1){
				if(LED_STATE[0] == GREEN_STATE || LED_STATE[0] == YELLOW_STATE){
					LED_STATE[0]= RED_STATE;
					LED_STATE[1]= GREEN_STATE;

				}
				if (LED_STATE[0] == RED_STATE){
					LED_STATE[0]= GREEN_STATE;
					LED_STATE[1]= RED_STATE;
				}
				ped_run();
				fsm_automatic_run(0);
				fsm_automatic_run(1);
			}
//			Active pedestrian
			if(isButtonPressed(3) == 1){
				PEDESTRIAN_MODE = 1;
				setTimer(3, PEDESTRIAN_DURATION*100);
			//	Active Buzzer
				HAL_GPIO_WritePin(WALKER_BUZZER_GPIO_Port, WALKER_BUZZER_Pin, SET);
			}
			if(isTimerOn(3)){
				PEDESTRIAN_MODE=0;
				HAL_GPIO_WritePin(WALKER_BUZZER_GPIO_Port, WALKER_BUZZER_Pin, RESET);
			}
			break;
		case MODE_2:
			displayDuration(2, tempDuration);
			if (isButtonPressed(0) == 1){
				tempDuration = YELLOW_DURATION;
				changeMode(MODE_3);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				tempDuration %= 100;
			}
			if (isButtonPressed(2) == 1){
				RED_DURATION = tempDuration;
			}
			if (isTimerOn(2) == 1){
//				HAL_GPIO_TogglePin(GPIOA, RED1_Pin);
//				HAL_GPIO_TogglePin(GPIOA, RED2_Pin);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin);
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin, SET);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_GPIO_Port);
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin, SET);
				setTimer(2, 25);
			}
			break;
		case MODE_3:
			displayDuration(3, tempDuration);
			if (isButtonPressed(0) == 1){
				tempDuration = GREEN_DURATION;
				changeMode(MODE_4);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				tempDuration %= 100;
			}
			if (isButtonPressed(2) == 1){
				YELLOW_DURATION = tempDuration;
			}
			if (isTimerOn(2) == 1){
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin);
				setTimer(2, 25);
			}
			break;
		case MODE_4:
			displayDuration(4, tempDuration);
			if (isButtonPressed(0) == 1){
				LED_STATE [0] = INIT_STATE;
				LED_STATE [1] = INIT_STATE;
				if(RED_DURATION != YELLOW_DURATION + GREEN_DURATION || !RED_DURATION || !YELLOW_DURATION || !GREEN_DURATION){
					RED_DURATION =RED_INNIT;
					YELLOW_DURATION= YELLOW_INNIT;
					GREEN_DURATION = GREEN_INNIT;
				}
				else{
					RED_INNIT = RED_DURATION;
					YELLOW_INNIT = YELLOW_DURATION;
					GREEN_INNIT = GREEN_DURATION;
				}
				PEDESTRIAN_DURATION = 2 * (RED_DURATION + YELLOW_DURATION + GREEN_DURATION);
				changeMode(MODE_1);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				tempDuration %= 100;
			}
			if (isButtonPressed(2) == 1){
				GREEN_DURATION = tempDuration;
			}
			if (isTimerOn(2) == 1){
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin, SET);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin);
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin, SET);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin);
				setTimer(2, 25);
			}
			break;
		default:
			MODE=MODE_1;
			break;
	}
	ped_run();
}


