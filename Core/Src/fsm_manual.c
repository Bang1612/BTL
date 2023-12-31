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



void fsm_manual_run(){

	switch(MODE){
		case MODE_1:
			fsm_automatic_run(0);
			fsm_automatic_run(1);

			if (isButtonPressed(0) == 1){
				tempDuration = RED_DURATION;
				changeMode(MODE_2);
				HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
//				Turn off pedestrian mode
				PEDESTRIAN_MODE = 0;
				ButtonInitializer(0);
			}
//			Change light on
			if(isButtonPressed(1) == 1){
				if(LED_STATE[0] == GREEN_STATE || LED_STATE[0] == YELLOW_STATE){
					LED_STATE[0]= RED_STATE;
					setTimer(0, RED_DURATION*100);
					LED_STATE[1]= GREEN_STATE;
					setTimer(1, GREEN_DURATION*100);
					if(PEDESTRIAN_MODE){
						setGreen(2);
					}

				}

				if (LED_STATE[0] == RED_STATE){
					LED_STATE[0]= GREEN_STATE;
					setTimer(0, GREEN_DURATION*100);
					LED_STATE[1]= RED_STATE;
					setTimer(1, RED_DURATION*100);
					if(PEDESTRIAN_MODE){
						setRed(2);
					}
				}
				ButtonInitializer(1);
			}

			if(isButtonPressed(3) == 1){
				PEDESTRIAN_MODE = 1;
				setTimer(3, PEDESTRIAN_DURATION*100);

			}
			if(isTimerOn(3)){
				PEDESTRIAN_MODE=0;
				setTrafficLightDefault(2);

			}
			break;
		case MODE_2:
			Display(2, tempDuration);
			if (isButtonPressed(0) == 1){
				tempDuration = YELLOW_DURATION;
				changeMode(MODE_3);
				ButtonInitializer(0);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				tempDuration %= 100;
				ButtonInitializer(1);
			}
			if(isButtonLongPressed(1)==1){
				if(isTimerOn(3) ==1){
					tempDuration++;
					tempDuration %= 100;
					setTimer(4,50);
				}
			}
			if (isButtonPressed(2) == 1){
				RED_DURATION = tempDuration;
				HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			}

			if (isTimerOn(2) == 1){

				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin);
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin, RESET);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin);
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin, RESET);
				setTimer(2, 10);
			}
			break;
		case MODE_3:
			Display(3, tempDuration);
			if (isButtonPressed(0) == 1){
				tempDuration = GREEN_DURATION;
				changeMode(MODE_4);
				ButtonInitializer(0);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				tempDuration %= 100;
				ButtonInitializer(1);
			}
			if(isButtonLongPressed(1)==1){
				if(isTimerOn(3) ==1){
					tempDuration++;
					tempDuration %= 100;
					setTimer(4,50);
				}
			}
			if (isButtonPressed(2) == 1){
				YELLOW_DURATION = tempDuration;
				HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			}
			if (isTimerOn(2) == 1){
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin);
				setTimer(2, 10);
			}
			break;
		case MODE_4:
			Display(4, tempDuration);
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
				ButtonInitializer(0);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				tempDuration %= 100;
				ButtonInitializer(1);
			}
			if(isButtonLongPressed(1)==1){
				if(isTimerOn(3) ==1){
					tempDuration++;
					tempDuration %= 100;
					setTimer(4,50);
				}
			}
			if (isButtonPressed(2) == 1){
				GREEN_DURATION = tempDuration;
				HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			}
			if (isTimerOn(2) == 1){
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_1_0_GPIO_Port, TRAFFIC_LIGHT_1_0_Pin, RESET);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_1_1_GPIO_Port, TRAFFIC_LIGHT_1_1_Pin);
				HAL_GPIO_WritePin(TRAFFIC_LIGHT_2_0_GPIO_Port, TRAFFIC_LIGHT_2_0_Pin, RESET);
				HAL_GPIO_TogglePin(TRAFFIC_LIGHT_2_1_GPIO_Port, TRAFFIC_LIGHT_2_1_Pin);
				setTimer(2, 10);
			}
			break;
		default:
			MODE=MODE_1;
			break;
	}

}


