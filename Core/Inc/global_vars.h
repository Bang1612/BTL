/*
 * global_var.h
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#ifndef INC_GLOBAL_VARS_H_
#define INC_GLOBAL_VARS_H_

#include <timer.h>
#include "button.h"
#include "transfer.h"
#include "main.h"
#include "traffic_light.h"
#include "fsm_auto.h"
#include "fsm_manual.h"
#include "pedestrian.h"
#include <stdio.h>

#define INIT_STATE 1
#define RED_STATE 2
#define GREEN_STATE 3
#define YELLOW_STATE 4

#define MODE_1 11
#define MODE_2 12
#define MODE_3 13
#define MODE_4 14

extern int LED_STATE [2];
extern int MODE;
extern int PEDESTRIAN_MODE;
extern int RED_DURATION;
extern int YELLOW_DURATION;
extern int GREEN_DURATION;
extern int RED_INNIT;
extern int YELLOW_INNIT;
extern int GREEN_INNIT;
extern int PEDESTRIAN_DURATION;
extern int COUNTER[2];
extern char info[15];

#endif /* INC_GLOBAL_VARS_H_ */
