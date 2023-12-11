/*
 * button.h
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global_vars.h"
#include "stm32f1xx_hal.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define NUMBER_OF_BUTTON 4

struct{
	int reg[5];
	int is_pressed;
	int is_long_pressed;
	int timer;
	GPIO_TypeDef *gpio;
	uint16_t pin;
} button[NUMBER_OF_BUTTON];
void ButtonInitializer(int i);
void buttonInnit(void);
int isButtonPressed(int i);
int isButtonLongPressed(int index);

void getKeyInput(void);

#endif /* INC_BUTTON_H_ */
