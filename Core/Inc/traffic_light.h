/*
 * traffic_light.h
 *
 *  Created on: Dec 4, 2023
 *      Author: MY PC
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global_vars.h"


void setTrafficLightDefault(int lane);
void setRed(int lane);
void setGreen(int lane);
void setAmber(int lane);

void display7SEG(int type, int num);

#endif /* INC_TRAFFIC_LIGHT_H_ */
