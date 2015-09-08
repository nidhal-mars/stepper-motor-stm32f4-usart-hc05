#ifndef __STEPPER_H
#define __STEPPER_H
#include "stm32f4_discovery.h"
#include "delay.h"

void stepper_Init();
void Turn(int speed);
#endif
