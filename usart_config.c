#include "usart_config.h"

void usart_lowLevelInit(){
  GPIO_InitTypeDef GPIO_InitStructure;
 
  /**************************GPIO Configuration*****************************/
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
   
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
 
  /* Connect USART pins to AF */
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);
  //*************************USARTx configuration *****************************
  USART_InitTypeDef USART_InitStructure;
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
 
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART3, &USART_InitStructure);
  USART_Cmd(USART3, ENABLE);
  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
  
  //***************************Interruption Config***********************************
  NVIC_InitTypeDef NVIC_InitStructure;
 
  /* Enable the USART3 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 }

//----------------------------Fonction de Reception ---------------------------------

__IO uint8_t cursor;
__IO char buffer[50] , c ;
extern int speed ;
extern __IO char result[50];

void usart_receive(char c)
{
  if(c=='\r'||c=='\n')
  {
    buffer[cursor]='\0';
    strcpy((char*)result,(char*)buffer);
    cursor=0;
    if(atoi((char*)result))
      speed=atoi((char*)result);
    
  }
  else
  {buffer[cursor++]=c;}
  
}

