/*
 * fsm_auto.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#include "fsm_auto.h"

void fsm_automatic_run(int lane){

	Display(timer[0].count / 100, timer[1].count / 100);
	if (PEDESTRIAN_MODE && LED_STATE[0] == RED_STATE) {
		int freq = ((RED_DURATION * 100 - timer[0].count) / RED_DURATION)*21 ;
            if(timer[0].count >= (RED_DURATION * 60) && timer[0].count <= (RED_DURATION * 80)) buzzer(0);
            else if(timer[0].count >= (RED_DURATION * 20) && timer[0].count <= (RED_DURATION * 40)) buzzer(0);
            else buzzer(freq);

	}


	if(LED_STATE[0] != RED_STATE){
		buzzer(0);
	}
	switch(LED_STATE[lane]){
		case INIT_STATE:
			setTrafficLightDefault(lane);
			if (lane == 0){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
				if(PEDESTRIAN_MODE){
					setGreen(2);
				}
			}
			else{
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, GREEN_DURATION*100);
			}
			break;
		case RED_STATE:
			setRed(lane);
			if(isTimerOn(lane) == 1){
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, GREEN_DURATION*100);
			}

			if(lane ==0 && PEDESTRIAN_MODE){
				setGreen(2);
			}
			break;
		case GREEN_STATE:
			setGreen(lane);
			if(isTimerOn(lane) == 1){
				LED_STATE[lane] = YELLOW_STATE;
				setTimer(lane, YELLOW_DURATION*100);
			}

			if(lane == 0 && PEDESTRIAN_MODE){
				setRed(2);
			}
			break;
		case YELLOW_STATE:
			setAmber(lane);
			if(isTimerOn(lane) == 1){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
			}

			if(lane ==0 && PEDESTRIAN_MODE){
				setRed(2);
			}
			break;
		default:
			break;
	}


}

