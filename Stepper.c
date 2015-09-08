#include "Stepper.h"


void stepper_Init(){
 GPIO_InitTypeDef GPIOD_Stepper;
 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  
 GPIOD_Stepper.GPIO_Mode = GPIO_Mode_OUT;
 GPIOD_Stepper.GPIO_OType = GPIO_OType_PP;
 GPIOD_Stepper.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
 GPIOD_Stepper.GPIO_PuPd = GPIO_PuPd_NOPULL;
 GPIOD_Stepper.GPIO_Speed = GPIO_Speed_100MHz;
 GPIO_Init(GPIOD,&GPIOD_Stepper);
}


void Turn(int speed)
{
 
              GPIO_Write(GPIOD,GPIO_Pin_12);
              delay_nms(speed);
              GPIO_Write(GPIOD,GPIO_Pin_12| GPIO_Pin_13);
              delay_nms(speed);
              GPIO_Write(GPIOD,GPIO_Pin_13);
              delay_nms(speed);
              GPIO_Write(GPIOD,GPIO_Pin_14|GPIO_Pin_13);
              delay_nms(speed);
              GPIO_Write(GPIOD,GPIO_Pin_14);
              delay_nms(speed);
              GPIO_Write(GPIOD,GPIO_Pin_14|GPIO_Pin_15);
              delay_nms(speed);
              GPIO_Write(GPIOD,GPIO_Pin_15);
              delay_nms(speed);
              GPIO_Write(GPIOD,GPIO_Pin_15|GPIO_Pin_12);
              delay_nms(speed);
}