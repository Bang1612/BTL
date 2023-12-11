/*
 * transfer.c
 *
 *  Created on: Dec 8, 2023
 *      Author: MY PC
 */
#include "transfer.h"

void Display(int n1, int n2){


	int i=0;
	if( n1 < 10) i+=1;
	if( n2 < 10) i+=2;
	switch(i){
	case 0:
		HAL_UART_Transmit(&huart3, ( void *) info, sprintf(info, "!7SEG:%d %d# \r", n1, n2), 1000);
		break;
	case 1:
		HAL_UART_Transmit(&huart3, ( void *) info, sprintf(info, "!7SEG:0%d %d# \r", n1, n2), 1000);
		break;
	case 2:
		HAL_UART_Transmit(&huart3, ( void *) info, sprintf(info, "!7SEG:%d 0%d# \r", n1, n2), 1000);
		break;
	case 3:
		HAL_UART_Transmit(&huart3, ( void *) info, sprintf(info, "!7SEG:0%d 0%d# \r", n1, n2), 1000);
		break;
	default:
		HAL_UART_Transmit(&huart3, ( void *) info, sprintf(info, "!7SEG:%d %d# \r", n1, n2), 1000);
		break;
	}


}
