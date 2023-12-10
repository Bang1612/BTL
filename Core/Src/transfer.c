/*
 * transfer.c
 *
 *  Created on: Dec 8, 2023
 *      Author: MY PC
 */
#include "transfer.h"

void Display(int n){
	if(n < 10){
		HAL_UART_Transmit(&huart1, ( void *) info1, sprintf(info1, "!7SEG:0%d#", n), 1000);
	}
	else{
		HAL_UART_Transmit(&huart1, ( void *) info1, sprintf(info1, "!7SEG:%d#", n), 1000);
	}
}
