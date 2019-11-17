#ifndef INTERRUPTABLE_H_
#define INTERRUPTABLE_H_

#include "interrupts.h"




class interruptable{

public:

interruptable();


virtual void handleInterrupts(int interruptType) = 0;
virtual void registerInterrupt() = 0;

private:
  

};



#endif