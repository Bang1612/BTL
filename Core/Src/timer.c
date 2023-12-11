/*
 * timer.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */
#include "timer.h"

//Timer 0: lane 1
//Timer 2: lane 2
//Timer 3: mode changing

void Innitial_Timer(int i){
	if(i == 0){
		timer[i].count =0;
		timer[i].flag =1;
	}
	else{
		timer[i].count =0;
		timer[i].flag =1;
		Innitial_Timer(i-1);
	}
}

void timerInnit(void){
	Innitial_Timer(NUMBER_OF_TIMER-1);
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
		RunTimer(index-1);
	}
}

void timerRun(void){
	RunTimer(NUMBER_OF_TIMER-1);
}

int isTimerOn(unsigned index){
	return timer[index].flag == 1;
}
