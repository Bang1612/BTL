/*
 * button.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */
#include "button.h"

//int button_flag [4] = {0, 0, 0, 0};
//
GPIO_TypeDef *BUTTON_PORT [4] = {BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port, WALKER_BUTTON_GPIO_Port};
uint16_t BUTTON_PIN [4] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin, WALKER_BUTTON_Pin};
//
//int BtnRegistor0 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
//int BtnRegistor1 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
//int BtnRegistor2 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
//int BtnRegistor3 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
//int TimerForKeyPress [4] = {500, 500, 500, 500};

void ButtonInitializer(int i){
	if(i==0){
		button[i].gpio= BUTTON_PORT[i];
		button[i].is_long_pressed=0;
		button[i].is_pressed=0;
		button[i].pin= BUTTON_PIN[i];
		button[i].reg[0]= button[i].reg[1] = button[i].reg[2] = button[i].reg[3] = button[i].reg[4] = NORMAL_STATE;
		button[i].timer= 500;
	}
	else{
		button[i].gpio= BUTTON_PORT[i];
		button[i].is_long_pressed=0;
		button[i].is_pressed=0;
		button[i].pin= BUTTON_PIN[i];
		button[i].reg[0]= button[i].reg[1] = button[i].reg[2] = button[i].reg[3] = button[i].reg[4] = NORMAL_STATE;
		button[i].timer= 500;
		ButtonInitializer(i-1);
	}
}

void buttonInnit(void){
	ButtonInitializer(NUMBER_OF_BUTTON -1);
}

int isButtonPressed(int index){
	return button[index].is_pressed;
}
int isButtonLongPressed(int index){
	return button[index].is_long_pressed;
}

//void subKeyProcess(int button){
//	button_flag[button] = 1;
//}


void getInput(int i){
//	BtnRegistor0[button] = BtnRegistor1[button];
//	BtnRegistor1[button] = BtnRegistor2[button];
//	BtnRegistor2[button] = HAL_GPIO_ReadPin(BUTTON_PORT[button], BUTTON_PIN[button]);
//	if ((BtnRegistor0[button] == BtnRegistor1[button]) && (BtnRegistor1[button] == BtnRegistor2[button]))
//	{
//		if (BtnRegistor3[button] != BtnRegistor2[button])
//		{
//			BtnRegistor3[button] = BtnRegistor2[button];
//			if (BtnRegistor2[button] == PRESSED_STATE)
//			{
//				subKeyProcess(button);
//				TimerForKeyPress[button] = 500;
//			}
//		}
//		else{
//			TimerForKeyPress[button]--;
//			if (TimerForKeyPress[button] <= 0)
//			{
//				BtnRegistor3[button] = NORMAL_STATE;
//			}
//		}
//	}
	if (i == 0) {
		button[i].reg[0] = button[i].reg[1];
		button[i].reg[1] = button[i].reg[2];
		button[i].reg[2] = button[i].reg[3];
		button[i].reg[3] = button[i].reg[4];
		button[i].reg[4] = HAL_GPIO_ReadPin(BUTTON_PORT[i], BUTTON_PIN[i]);
		if (button[i].reg[0] == button[i].reg[1]
				&& button[i].reg[1] == button[i].reg[2]
				&& button[i].reg[2] == button[i].reg[3]
				&& button[i].reg[3] == button[i].reg[4]) {
			if (button[i].reg[4] == PRESSED_STATE) {
				if (button[i].timer > 0) {
					button[i].timer--;

				}
				else {
					button[i].is_long_pressed = 1;
				}
				if (button[i].timer <= 490) {
					button[i].is_pressed = 1;
				}
			} else {
				button[i].is_pressed = 0;
				button[i].is_long_pressed = 0;
				button[i].timer = 500;
			}
		}
	}
	else {
		button[i].reg[0] = button[i].reg[1];
		button[i].reg[1] = button[i].reg[2];
		button[i].reg[2] = button[i].reg[3];
		button[i].reg[3] = button[i].reg[4];
		button[i].reg[4] = HAL_GPIO_ReadPin(BUTTON_PORT[i], BUTTON_PIN[i]);
		if (button[i].reg[0] == button[i].reg[1]
				&& button[i].reg[1] == button[i].reg[2]
				&& button[i].reg[2] == button[i].reg[3]
				&& button[i].reg[3] == button[i].reg[4]) {
			if (button[i].reg[4] == PRESSED_STATE) {
				button[i].is_pressed = 1;
				if (button[i].timer > 0) {
					button[i].timer--;
				} else {
					button[i].is_long_pressed = 1;
				}
			} else {
				button[i].is_pressed = 0;
				button[i].is_long_pressed = 0;
				button[i].timer = 500;
			}
		}
		getInput(i-1);
	}
}
void getKeyInput(void){
	getInput(NUMBER_OF_BUTTON-1);
}


