#include "interrupts.h"

//array of pointers to objects that system interrupt functions will call
interruptable * handlerPointers[sizeof(peripheralInterrupts)];


//system interrupt calls
extern "C"{



   void I2C1_EV_IRQHandler(void){

    handlerPointers[I2C1_IDX]->handleInterrupts(I2C_EV);
  
  }

   void I2C1_ER_IRQHandler(void)
  {
    

    handlerPointers[I2C1_IDX]->handleInterrupts(I2C_ER);

  }

  void USART1_IRQHandler(void)
  {

    handlerPointers[USART1_IDX]->handleInterrupts(0);

  }

  void USART2_IRQHandler(void)
  {

    handlerPointers[USART2_IDX]->handleInterrupts(0);

  }



}

