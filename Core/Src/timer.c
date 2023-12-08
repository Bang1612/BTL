/*
 * timer.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */
#include "timer.h"

//Timer 0: 1 sec for LED
//Timer 2: 500 ms
//Timer 3: 50ms for press



void timerInnit(unsigned int index){
	if(index ==0){
		timer[index].count=0;
		timer[index].flag=1;
	}
	else{
		timer[index].count=0;
		timer[index].flag=1;
		timerInnit(index--);
	}
}

void setTimer( unsigned int index, unsigned int count){
	if(index >= NUMBER_OF_TIMER){
		return;
	}
	timer[index].count=count;
	timer[index].flag=0;
}
void RunTimer(int index){
	if(index ==0){
		if(timer[index].count ==0){
			timer[index].flag=1;
		}
		else{
			timer[index].count--;
		}
	}
	else{
		if (timer[index].count == 0) {
			timer[index].flag = 1;
		} else {
			timer[index].count--;
		}
		RunTimer(index--);
	}
}

void timerRun(void){
	RunTimer(NUMBER_OF_TIMER);
}

int isTimerOn(unsigned index){
	return timer[index].flag;
}
