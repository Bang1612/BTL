/*
 * button.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */
#include "button.h"

int button_flag [4] = {0, 0, 0, 0};

GPIO_TypeDef *BUTTON_PORT [4] = {BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port, WALKER_BUTTON_GPIO_Port};
uint16_t BUTTON_PIN [4] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin, WALKER_BUTTON_Pin};

int BtnRegistor0 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int BtnRegistor1 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int BtnRegistor2 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int BtnRegistor3 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimerForKeyPress [4] = {500, 500, 500, 500};

int isButtonPressed(int button){
	if (button_flag[button] == 1){
		button_flag[button] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int button){
	button_flag[button] = 1;
}


void getKeyInput(int button){
	BtnRegistor0[button] = BtnRegistor1[button];
	BtnRegistor1[button] = BtnRegistor2[button];
	BtnRegistor2[button] = HAL_GPIO_ReadPin(BUTTON_PORT[button], BUTTON_PIN[button]);
	if ((BtnRegistor0[button] == BtnRegistor1[button]) && (BtnRegistor1[button] == BtnRegistor2[button]))
	{
		if (BtnRegistor3[button] != BtnRegistor2[button])
		{
			BtnRegistor3[button] = BtnRegistor2[button];
			if (BtnRegistor2[button] == PRESSED_STATE)
			{
				subKeyProcess(button);
				TimerForKeyPress[button] = 500;
			}
		}
		else{
			TimerForKeyPress[button]--;
			if (TimerForKeyPress[button] <= 0)
			{
				BtnRegistor3[button] = NORMAL_STATE;
			}
		}
	}
}


