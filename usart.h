/*
 * i2c.h
 *
 *  Created on: Jan 25, 2019
 *      Author: matt
 */

#ifndef USART_H_
#define USART_H_


#include "registers.h"
#include "reg_access.h"
#include "reg_access_dynamic.h"
#include "interruptable.h"
#include "interrupts.h"
#include "rcc.h"
#include "gpio.h"
#include "gpio_config.h"
#include "misc.h"
#include "circular_buffer.h"

extern interruptable * handlerPointers[sizeof(peripheralInterrupts)];

namespace USART{

  typedef uint32_t USARTRegisterType;
  
   
  namespace BaseRegisters
  {
      
    constexpr USARTRegisterType USART1Base = 0x40011000U;
    constexpr USARTRegisterType USART2Base = 0x40004400U;
    constexpr USARTRegisterType USART3Base = 0x40004800U;
    constexpr USARTRegisterType USART4Base = 0x40004C00U;
    constexpr USARTRegisterType USART5Base = 0x40005000U;
    constexpr USARTRegisterType USART6Base = 0x40011400U;
    constexpr USARTRegisterType USART7Base = 0x40007800U;
    constexpr USARTRegisterType USART8Base = 0x40007C00U;

  }

  namespace StatusRegister
  {

    constexpr USARTRegisterType RegisterOffset = 0x00U;
    constexpr USARTRegisterType RegisterReset = 0x00000000U;
//    constexpr USARTRegisterType RegisterReset = 0x000000C0U;


    constexpr USARTRegisterType ClearToSendFlag = stm32fxx::bits::BIT9;
    constexpr USARTRegisterType LineBreakDetection = stm32fxx::bits::BIT8;
    constexpr USARTRegisterType TXEmpty = stm32fxx::bits::BIT7;
    constexpr USARTRegisterType TransmissionComplete = stm32fxx::bits::BIT6;
    constexpr USARTRegisterType RXNotEmpty = stm32fxx::bits::BIT5;
    constexpr USARTRegisterType IdleLineDetected = stm32fxx::bits::BIT4;
    constexpr USARTRegisterType OverrunError = stm32fxx::bits::BIT3;
    constexpr USARTRegisterType NoiseDetected = stm32fxx::bits::BIT2;
    constexpr USARTRegisterType FramingError = stm32fxx::bits::BIT1;
    constexpr USARTRegisterType ParityError = stm32fxx::bits::BIT0;

  }

  namespace DataRegister
  {

    constexpr USARTRegisterType RegisterOffset = 0x04U;
    constexpr USARTRegisterType RegisterReset = 0x00U;


  }


  namespace BaudRateRegister
  {
    
    constexpr USARTRegisterType RegisterOffset = 0x08U;
    constexpr USARTRegisterType RegisterReset = 0x00U;


  }

  namespace ControlRegister1
  {
    
    constexpr USARTRegisterType RegisterOffset = 0x0CU;
    constexpr USARTRegisterType RegisterReset = 0x00U;


    constexpr USARTRegisterType OversamplingMode = stm32fxx::bits::BIT15;
    constexpr USARTRegisterType UsartEnable = stm32fxx::bits::BIT13;
    constexpr USARTRegisterType WordLength = stm32fxx::bits::BIT12;
    constexpr USARTRegisterType WakeupMethod = stm32fxx::bits::BIT11;
    constexpr USARTRegisterType ParityControlEnable = stm32fxx::bits::BIT10;
    constexpr USARTRegisterType ParitySelection = stm32fxx::bits::BIT9;
    constexpr USARTRegisterType ParityIE = stm32fxx::bits::BIT8;
    constexpr USARTRegisterType TXEmptyInterruptEnable = stm32fxx::bits::BIT7;
    constexpr USARTRegisterType TXCompleteIE = stm32fxx::bits::BIT6;
    constexpr USARTRegisterType RXNotEmptyIE = stm32fxx::bits::BIT5;
    constexpr USARTRegisterType IdleIE = stm32fxx::bits::BIT4;
    constexpr USARTRegisterType TransmitterEnable = stm32fxx::bits::BIT3;
    constexpr USARTRegisterType ReceiverEnable = stm32fxx::bits::BIT2;
    constexpr USARTRegisterType ReceiverWakeup = stm32fxx::bits::BIT1;
    constexpr USARTRegisterType SendBreak = stm32fxx::bits::BIT0;


  }

  namespace ControlRegister2
  {
    
    constexpr USARTRegisterType RegisterOffset = 0x10U;
    constexpr USARTRegisterType RegisterReset = 0x00U;

    constexpr USARTRegisterType LINModeEnable = stm32fxx::bits::BIT14;
    constexpr USARTRegisterType ClockEnable = stm32fxx::bits::BIT11;
    constexpr USARTRegisterType ClockPolarity = stm32fxx::bits::BIT10;
    constexpr USARTRegisterType ClockPhase = stm32fxx::bits::BIT9;
    constexpr USARTRegisterType LastBitClockPulse = stm32fxx::bits::BIT8;
    constexpr USARTRegisterType LINBreakDetectionIE = stm32fxx::bits::BIT6;
    constexpr USARTRegisterType LINBreakDetectionLength = stm32fxx::bits::BIT5;

    namespace StopBits
    {
      constexpr USARTRegisterType OneStopBit = 0x00U;
      constexpr USARTRegisterType HalfStopBit = 0x1000U;
      constexpr USARTRegisterType TwoStopBits = 0x2000U;
      constexpr USARTRegisterType OneAndHalfStopBits = 0x3000U;

    }


  }

  namespace ControlRegister3
  {

    constexpr USARTRegisterType RegisterOffset = 0x14U;
    constexpr USARTRegisterType RegisterReset = 0x00U;

    constexpr USARTRegisterType OneSampleBit = stm32fxx::bits::BIT11;
    constexpr USARTRegisterType ClearToSendIE = stm32fxx::bits::BIT10;
    constexpr USARTRegisterType ClearToSendEnable = stm32fxx::bits::BIT9;
    constexpr USARTRegisterType ReadyToSendEnable = stm32fxx::bits::BIT8;
    constexpr USARTRegisterType DMATXEnable = stm32fxx::bits::BIT7;
    constexpr USARTRegisterType DMARXEnable = stm32fxx::bits::BIT6;
    constexpr USARTRegisterType SmartCardEnable = stm32fxx::bits::BIT5;
    constexpr USARTRegisterType SmartCardNACKEnable = stm32fxx::bits::BIT4;
    constexpr USARTRegisterType HalfDuplexSelection = stm32fxx::bits::BIT3;
    constexpr USARTRegisterType IrDALowPower = stm32fxx::bits::BIT2;
    constexpr USARTRegisterType IrDAModeEnable = stm32fxx::bits::BIT1;
    constexpr USARTRegisterType ErrorIE = stm32fxx::bits::BIT0;

  }
  
  //Bits [15:8] used for guard time in Smartcard Mode
  //Bits [7:0]  used for prescaler in IrDA and Smartcard Mode
  namespace GuardTimePrescalerRegister
  {

    constexpr USARTRegisterType RegisterOffset = 0x18U;
    constexpr USARTRegisterType RegisterReset = 0x00U;

    //Used in IRdA and Smartcard Modes
    namespace PrescalerValues
    {



    }




  }

 
  
  class Usart : public interruptable
  {

    public:

    Usart(USART::USARTRegisterType baseRegister, util::circular_buffer<uint8_t> * TxBufferPointer);
    void handleInterrupts(int interruptType);
    void sendBytes(uint8_t data);

    private:

    //Register Addresses
    USART::USARTRegisterType baseRegister;
    USART::USARTRegisterType statusRegister;
    USART::USARTRegisterType dataRegister;
    USART::USARTRegisterType baudRateRegister;
    USART::USARTRegisterType controlRegister1;
    USART::USARTRegisterType controlRegister2;
    USART::USARTRegisterType controlRegister3;
    USART::USARTRegisterType guardTimePrescalerRegister;

    uint32_t usartStatus;

    PinType TXPin;
    PinType RXPin;
    GPIOxRegisterType TXGPIOBank;
    GPIOxRegisterType RXGPIOBank;
    AlternateFunctionType pinAF;
    util::circular_buffer<uint8_t> * txBufPtr;
    bool hasData;

    void registerInterrupt();
    int init();


  };



}








#endif