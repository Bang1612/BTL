/*
 * fsm_auto.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#include "fsm_auto.h"

void fsm_automatic_run(int lane){
	if (timer[lane].count % 100 == 0){
		int remaining_time = timer[lane].count / 100;
		Display(remaining_time);
		if(!lane && PEDESTRIAN_MODE){
			int freq= (RED_DURATION *100 - remaining_time) *10;
			buzzer(freq);
		}
	}
	switch(LED_STATE[lane]){
		case INIT_STATE:
			setTrafficLightDefault(lane);
			if (lane == 0){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
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
			break;
		case GREEN_STATE:
			setGreen(lane);
			if(isTimerOn(lane) == 1){
				LED_STATE[lane] = YELLOW_STATE;
				setTimer(lane, YELLOW_DURATION*100);
			}
			break;
		case YELLOW_STATE:
			setAmber(lane);
			if(isTimerOn(lane) == 1){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
			}
			break;
		default:
			break;
	}


}
