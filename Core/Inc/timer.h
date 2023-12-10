/*
 * timer.h
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define NUMBER_OF_TIMER 5

struct {
	unsigned int count;
	int flag;
} timer[NUMBER_OF_TIMER];
// Timer 0 : lane 0
// Timer 1: lane 1
void timerInnit(void);
void setTimer( unsigned int index, unsigned int count);
void timerRun(void);
int isTimerOn(unsigned int index);


#endif /* INC_TIMER_H_ */
