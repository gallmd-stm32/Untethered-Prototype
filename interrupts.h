#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "interruptable.h"
#include "stm32f4xx.h"



enum peripheralInterrupts
{
  I2C1_IDX,
  I2C2_IDX,
  I2C3_IDX,
  USART1_IDX,
  USART2_IDX,
  USART3_IDX,
  USART4_IDX,
  USART5_IDX,
  USART6_IDX,
  USART7_IDX,
  USART8_IDX

 };

 enum interruptSource
 {

  I2C_EV,
  I2C_ER

 };



 #endif