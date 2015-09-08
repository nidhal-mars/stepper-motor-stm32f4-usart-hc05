#ifndef __USART_CONFIG_H
#define __USART_CONFIG_H

#include "stm32f4xx.h"
#include "String.h"
#include "stdlib.h"
#include "Ctype.h"

void usart_lowLevelInit();
void usart_receive(char c);
#endif