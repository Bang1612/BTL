/*
 * global_vars.c
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#include "global_vars.h"

int LED_STATE [2] = {INIT_STATE, INIT_STATE};
int MODE = MODE_1;
int PEDESTRIAN_MODE = 0;

int RED_DURATION = 7;
int YELLOW_DURATION = 2;
int GREEN_DURATION = 5;
int RED_INNIT = 7;
int YELLOW_INNIT = 2;
int GREEN_INNIT = 5;
int PEDESTRIAN_DURATION = 20;
int BUZZER_DURATION = 2;

char info1[20];
char info2[20];
