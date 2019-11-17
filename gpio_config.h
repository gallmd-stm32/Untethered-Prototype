#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#include "gpio.h"
#include "rcc.h"


          
struct gpio_config final
{
  
  static void pinSetup(GPIOxRegisterType gpio_bank,
         PinType pinNumber,
         GpioModeType mode,
         OutputType outputType,
	 OutputSpeedType outputSpeed,
	 PullUpPullDownType pullUpPullDown,
	 AlternateFunctionType alternateFunction){

                 //Enable RCC_AHB1 Clock
                rcc::RCCRegisterType bankEnable;
                if(gpio_bank == GPIOxBaseRegisters::GPIO_A){
              
                  bankEnable = rcc::RccAHB1EnableRegister::GpioA;
                }   

                if(gpio_bank == GPIOxBaseRegisters::GPIO_B){
          
                  bankEnable = rcc::RccAHB1EnableRegister::GpioB;

                }   

                if(gpio_bank == GPIOxBaseRegisters::GPIO_C){
         
                  bankEnable = rcc::RccAHB1EnableRegister::GpioC;

                } 
                if(gpio_bank == GPIOxBaseRegisters::GPIO_D){
                
                  bankEnable = rcc::RccAHB1EnableRegister::GpioD;

                }              
                if(gpio_bank == GPIOxBaseRegisters::GPIO_E){
                  
                  bankEnable = rcc::RccAHB1EnableRegister::GpioE;
          
                }  
                if(gpio_bank == GPIOxBaseRegisters::GPIO_F){
             
                  bankEnable = rcc::RccAHB1EnableRegister::GpioF;

                }                                           
                if(gpio_bank == GPIOxBaseRegisters::GPIO_G){
               
                  bankEnable = rcc::RccAHB1EnableRegister::GpioG;

                } 
                if(gpio_bank == GPIOxBaseRegisters::GPIO_H){

                  bankEnable = rcc::RccAHB1EnableRegister::GpioH;
                }
                if(gpio_bank == GPIOxBaseRegisters::GPIO_I){

                  bankEnable = rcc::RccAHB1EnableRegister::GpioI;

                }    
                  dynamic_access<rcc::RCCRegisterType, 
                  rcc::RCCRegisterType>::reg_or( 
                  rcc::BaseRegisters::RccBaseRegister+rcc::RccAHB1EnableRegister::RegisterOffset, 
                  bankEnable);

		//set mode register
		uint32_t tempMask = 0x00U;
		tempMask = mode << ((pinNumber-1) * 2);

//		dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(GPIOxModeRegister, tempMask);

                dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(gpio_bank, tempMask);
                

		//set ouput type register
		dynamic_access<GPIOxRegisterType, OutputType>::reg_or(gpio_bank + RegisterOffsets::ModeRegisterOffset, (outputType << (pinNumber-1)));

		//set output speed register
		tempMask = 0x0U;
		tempMask = outputSpeed << ((pinNumber-1) * 2);
		dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(gpio_bank + RegisterOffsets::OutputSpeedRegisterOffset, tempMask);

		//set pull-up/pull-down register
		tempMask = 0x0U;
		tempMask = pullUpPullDown << ((pinNumber-1) * 2);
		dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(gpio_bank + RegisterOffsets::PullUpPullDownRegisterOffset, tempMask);

		//Set Alternate Function Register
		if(pinNumber <= PINS::PIN7){
			tempMask = 0x0U;
			tempMask = alternateFunction << ((pinNumber - 1) * 4);
			dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(gpio_bank + RegisterOffsets::AlternateFunctionLowRegisterOffset, tempMask);
		}else{
			tempMask = 0x0U;
			tempMask = alternateFunction << ((pinNumber - 9) * 4);
			dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(gpio_bank + RegisterOffsets::AlternateFunctionHighRegisterOffset, tempMask);

		}

         }

};

#endif