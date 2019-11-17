
#ifndef RCC_H_
#define RCC_H_

#include "reg_access.h"
#include "reg_access_dynamic.h"
#include "registers.h"

namespace rcc {

typedef uint32_t RCCRegisterType; 


  namespace BaseRegisters
  {
    constexpr RCCRegisterType RccBaseRegister = 0x40023800U;
    
  }

  namespace RccClockControlRegister {

    constexpr RCCRegisterType RegisterOffset = 0x00U;
    constexpr RCCRegisterType RegisterReset = 0x00000083U;

    constexpr RCCRegisterType PLLI2SReady = stm32fxx::bits::BIT27;
    constexpr RCCRegisterType PLLI2SON = stm32fxx::bits::BIT26;
    constexpr RCCRegisterType MainPLLReady = stm32fxx::bits::BIT25;
    constexpr RCCRegisterType MainPLLOn = stm32fxx::bits::BIT24;
    constexpr RCCRegisterType ClockSecuritySystemEnable = stm32fxx::bits::BIT19;
    constexpr RCCRegisterType HSEBypass = stm32fxx::bits::BIT18;
    constexpr RCCRegisterType HSEReady = stm32fxx::bits::BIT17;
    constexpr RCCRegisterType HSEOn = stm32fxx::bits::BIT16;
    constexpr RCCRegisterType HSIReady = stm32fxx::bits::BIT1;
    constexpr RCCRegisterType HSIOn = stm32fxx::bits::BIT0;

  }

  namespace RccAHB1EnableRegister{

    constexpr RCCRegisterType RegisterOffset = 0x30U;
    constexpr RCCRegisterType RegisterReset = 0x00100000U;
    
    constexpr RCCRegisterType OtgHsulpi = stm32fxx::bits::BIT30;
    constexpr RCCRegisterType OtgHSEn = stm32fxx::bits::BIT29;
    constexpr RCCRegisterType EthernetMacPTP = stm32fxx::bits::BIT28;
    constexpr RCCRegisterType EthernetReception = stm32fxx::bits::BIT27;
    constexpr RCCRegisterType EthernetTransmission = stm32fxx::bits::BIT26;
    constexpr RCCRegisterType EthernetMAC = stm32fxx::bits::BIT25;
    constexpr RCCRegisterType DMA2DEN = stm32fxx::bits::BIT23;
    constexpr RCCRegisterType DMA2EN = stm32fxx::bits::BIT22;
    constexpr RCCRegisterType DMA1EN = stm32fxx::bits::BIT21;
    constexpr RCCRegisterType CcmDataRam = stm32fxx::bits::BIT20;
    constexpr RCCRegisterType BackupSramInterface = stm32fxx::bits::BIT18;
    constexpr RCCRegisterType CRCEN = stm32fxx::bits::BIT12;
    constexpr RCCRegisterType GpioK = stm32fxx::bits::BIT10;
    constexpr RCCRegisterType GpioJ = stm32fxx::bits::BIT9;
    constexpr RCCRegisterType GpioI = stm32fxx::bits::BIT8;
    constexpr RCCRegisterType GpioH = stm32fxx::bits::BIT7;
    constexpr RCCRegisterType GpioG = stm32fxx::bits::BIT6;
    constexpr RCCRegisterType GpioF = stm32fxx::bits::BIT5;
    constexpr RCCRegisterType GpioE = stm32fxx::bits::BIT4;
    constexpr RCCRegisterType GpioD = stm32fxx::bits::BIT3;
    constexpr RCCRegisterType GpioC = stm32fxx::bits::BIT2;
    constexpr RCCRegisterType GpioB = stm32fxx::bits::BIT1;
    constexpr RCCRegisterType GpioA = stm32fxx::bits::BIT0;


  }

  namespace RccAPB1EnableRegister
{

  constexpr RCCRegisterType RegisterOffset = 0x40U;
  constexpr RCCRegisterType RegisterReset = 0x00U;

  constexpr RCCRegisterType UART8Enable = stm32fxx::bits::BIT31;
  constexpr RCCRegisterType UART7Enable = stm32fxx::bits::BIT30;

  constexpr RCCRegisterType DACEnable = stm32fxx::bits::BIT29;

  constexpr RCCRegisterType PowerInterface = stm32fxx::bits::BIT28;

  constexpr RCCRegisterType Can2Enable = stm32fxx::bits::BIT26;
  constexpr RCCRegisterType Can1Enable = stm32fxx::bits::BIT25;

  constexpr RCCRegisterType I2C3Enable = stm32fxx::bits::BIT23;
  constexpr RCCRegisterType I2C2Enable = stm32fxx::bits::BIT22;
  constexpr RCCRegisterType I2C1Enable = stm32fxx::bits::BIT21;

  constexpr RCCRegisterType UART5Enable = stm32fxx::bits::BIT20;
  constexpr RCCRegisterType UART4Enable = stm32fxx::bits::BIT19;
  constexpr RCCRegisterType USART3Enable = stm32fxx::bits::BIT18;
  constexpr RCCRegisterType USART2Enable = stm32fxx::bits::BIT17;

  constexpr RCCRegisterType SPI3Enable = stm32fxx::bits::BIT15;
  constexpr RCCRegisterType SPI2Enable = stm32fxx::bits::BIT14;

  constexpr RCCRegisterType WindowWatchdog = stm32fxx::bits::BIT11;

  constexpr RCCRegisterType Timer14 = stm32fxx::bits::BIT8;
  constexpr RCCRegisterType Timer13 = stm32fxx::bits::BIT7;
  constexpr RCCRegisterType Timer12 = stm32fxx::bits::BIT6;
  constexpr RCCRegisterType Timer7 = stm32fxx::bits::BIT5;
  constexpr RCCRegisterType Timer6 = stm32fxx::bits::BIT4;
  constexpr RCCRegisterType Timer5 = stm32fxx::bits::BIT3;
  constexpr RCCRegisterType Timer4 = stm32fxx::bits::BIT2;
  constexpr RCCRegisterType Timer3 = stm32fxx::bits::BIT1;
  constexpr RCCRegisterType Timer2 = stm32fxx::bits::BIT0;


}


namespace RccAPB2EnableRegister {

  constexpr RCCRegisterType RegisterOffset = 0x44U;
  constexpr RCCRegisterType RegisterReset = 0x00U;

  constexpr RCCRegisterType Timer11 = stm32fxx::bits::BIT18;
  constexpr RCCRegisterType Timer10 = stm32fxx::bits::BIT17;
  constexpr RCCRegisterType Timer9 = stm32fxx::bits::BIT16;

  constexpr RCCRegisterType SystemConfigurationController = stm32fxx::bits::BIT14;

  constexpr RCCRegisterType SPI1Enable = stm32fxx::bits::BIT12;

  constexpr RCCRegisterType SDIOEnable = stm32fxx::bits::BIT11;

  constexpr RCCRegisterType ADC3Enable = stm32fxx::bits::BIT10;
  constexpr RCCRegisterType ADC2Enable = stm32fxx::bits::BIT9;
  constexpr RCCRegisterType ADC1Enable = stm32fxx::bits::BIT8;

  constexpr RCCRegisterType USART6Enable = stm32fxx::bits::BIT5;
  constexpr RCCRegisterType USART1Enable = stm32fxx::bits::BIT4;

  constexpr RCCRegisterType Timer8 = stm32fxx::bits::BIT1;
  constexpr RCCRegisterType Timer1 = stm32fxx::bits::BIT0;

}

}

#endif 