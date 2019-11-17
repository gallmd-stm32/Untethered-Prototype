/*
 * gpio.h
 *
 *  Created on: Oct 11, 2018
 *      Author: matt
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "reg_access.h"
#include "reg_access_dynamic.h"
#include "registers.h"
#include "rcc.h"


typedef uint32_t AlternateFunctionType;
typedef uint32_t PinType;
typedef uint32_t GpioModeType;
typedef uint32_t OutputType;
typedef uint32_t OutputSpeedType;
typedef uint32_t PullUpPullDownType;
typedef uint32_t GPIOxRegisterType;

namespace GPIOxBaseRegisters{


	constexpr GPIOxRegisterType GPIO_A = 0x40020000U;
	constexpr GPIOxRegisterType GPIO_B = 0x40020400U;
	constexpr GPIOxRegisterType GPIO_C = 0x40020800U;
	constexpr GPIOxRegisterType GPIO_D = 0x40020C00U;
	constexpr GPIOxRegisterType GPIO_E = 0x40021000U;
	constexpr GPIOxRegisterType GPIO_F = 0x40021400U;
	constexpr GPIOxRegisterType GPIO_G = 0x40021800U;
	constexpr GPIOxRegisterType GPIO_H = 0x40021C00U;
	constexpr GPIOxRegisterType GPIO_I = 0x40022000U;


}

namespace AlternateFunction{

	//GPIO Alternate functions
	constexpr AlternateFunctionType AF0 	= 0x00000000U;
	constexpr AlternateFunctionType AF1 	= 0x00000001U;
	constexpr AlternateFunctionType AF2 	= 0x00000002U;
	constexpr AlternateFunctionType AF3 	= 0x00000003U;
	constexpr AlternateFunctionType AF4 	= 0x00000004U;
	constexpr AlternateFunctionType AF5 	= 0x00000005U;
	constexpr AlternateFunctionType AF6 	= 0x00000006U;
	constexpr AlternateFunctionType AF7 	= 0x00000007U;
	constexpr AlternateFunctionType AF8 	= 0x00000008U;
	constexpr AlternateFunctionType AF9 	= 0x00000009U;
	constexpr AlternateFunctionType AF10 	= 0x0000000AU;
	constexpr AlternateFunctionType AF11 	= 0x0000000BU;
	constexpr AlternateFunctionType AF12 	= 0x0000000CU;
	constexpr AlternateFunctionType AF13 	= 0x0000000DU;
	constexpr AlternateFunctionType AF14 	= 0x0000000EU;
	constexpr AlternateFunctionType AF15 	= 0x0000000FU;

}

namespace PINS {

	constexpr PinType PIN0 		= 1U;
	constexpr PinType PIN1 		= 2U;
	constexpr PinType PIN2 		= 3U;
	constexpr PinType PIN3 		= 4U;
	constexpr PinType PIN4 		= 5U;
	constexpr PinType PIN5 		= 6U;
	constexpr PinType PIN6 		= 7U;
	constexpr PinType PIN7 		= 8U;
	constexpr PinType PIN8 		= 9U;
	constexpr PinType PIN9 		= 10U;
	constexpr PinType PIN10 	= 11U;
	constexpr PinType PIN11 	= 12U;
	constexpr PinType PIN12 	= 13U;
	constexpr PinType PIN13 	= 14U;
	constexpr PinType PIN14 	= 15U;
	constexpr PinType PIN15 	= 16U;

}

	namespace GpioModes{

	constexpr GpioModeType Input 				= 0x00000000U;
	constexpr GpioModeType Output 				= 0x00000001U;
	constexpr GpioModeType AlternateFunction 	= 0x00000002U;
	constexpr GpioModeType AnalogMode 			= 0x00000003U;

}

namespace OutputTypes{

	constexpr OutputType PushPull 	= 0x00000000U;
	constexpr OutputType OpenDrain 	= 0x00000001U;

}

namespace OutputSpeed{

	constexpr OutputSpeedType LowSpeed 			= 0x00000000U;
	constexpr OutputSpeedType MediumSpeed 		= 0x00000001U;
	constexpr OutputSpeedType HighSpeed 		= 0x00000002U;
	constexpr OutputSpeedType VeryHighSpeeed 	= 0x00000003U;

}

namespace PullUpPullDown {

	constexpr PullUpPullDownType NoPullUpPullDown 	= 0x00000000U;
	constexpr PullUpPullDownType PullUp 			= 0x00000001U;
	constexpr PullUpPullDownType PullDown 			= 0x00000002U;

}

namespace RegisterOffsets{

	constexpr GPIOxRegisterType ModeRegisterOffset 					= 0x00000000U;
	constexpr GPIOxRegisterType OutputTypeRegisterOffset 			= 0x00000004U;
	constexpr GPIOxRegisterType OutputSpeedRegisterOffset 			= 0x00000008U;
	constexpr GPIOxRegisterType PullUpPullDownRegisterOffset 		= 0x0000000CU;
	constexpr GPIOxRegisterType InputDataRegisterOffset 			= 0x00000010U;
	constexpr GPIOxRegisterType OutputDataRegisterOffset 			= 0x00000014U;
	constexpr GPIOxRegisterType BitSetResetLowRegisterOffset 		= 0x00000018U;
	constexpr GPIOxRegisterType BitSetResetHighRegisterOffset 		= 0x0000001AU;
	constexpr GPIOxRegisterType LockRegisterOffset 					= 0x0000001CU;
	constexpr GPIOxRegisterType AlternateFunctionLowRegisterOffset 	= 0x00000020U;
	constexpr GPIOxRegisterType AlternateFunctionHighRegisterOffset = 0x00000024U;

}

template<
	const GPIOxRegisterType gpio_bank,
	const PinType pinNumber,
	const GpioModeType mode,
	const OutputType outputType,
	const OutputSpeedType outputSpeed,
	const PullUpPullDownType pullUpPullDown,
	const AlternateFunctionType alternateFunction>
class GPIO{


public:

	GPIO(){

                //Enable RCC_AHB1 Clock
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

                dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(GPIOxModeRegister, tempMask);
                

		//set ouput type register
		reg_access<GPIOxRegisterType, OutputType, GPIOxOutputTypeRegister, (outputType << (pinNumber-1))>::reg_or();

		//set output speed register
		tempMask = 0x0U;
		tempMask = outputSpeed << ((pinNumber-1) * 2);
		dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(GPIOxOuputSpeedRegister, tempMask);

		//set pull-up/pull-down register
		tempMask = 0x0U;
		tempMask = pullUpPullDown << ((pinNumber-1) * 2);
		dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(GPIOxPullUpPullDownRegister, tempMask);

		//Set Alternate Function Register
		if(pinNumber <= PINS::PIN7){
			tempMask = 0x0U;
			tempMask = alternateFunction << ((pinNumber - 1) * 4);
			dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(GPIOxAlternateFunctionLowRegister, tempMask);
		}else{
			tempMask = 0x0U;
			tempMask = alternateFunction << ((pinNumber - 9) * 4);
			dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(GPIOxAlternateFunctionHighRegister, tempMask);

		}



	}

	void toggle() const{

		reg_access<GPIOxRegisterType, GPIOxRegisterType, GPIOxOutputDataRegister, bitPosition>::reg_xor();
	}

	void set() const{

		reg_access<GPIOxRegisterType, GPIOxRegisterType, GPIOxOutputDataRegister, bitPosition>::reg_or();

	}

	void clear() const{

		reg_access<GPIOxRegisterType, GPIOxRegisterType, GPIOxOutputDataRegister, bitPosition>::reg_and_not();

	}


private:
	static constexpr GPIOxRegisterType GPIOxBaseRegister = gpio_bank;
	static constexpr GPIOxRegisterType GPIOxModeRegister = gpio_bank + RegisterOffsets::ModeRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxOutputTypeRegister = gpio_bank + RegisterOffsets::OutputTypeRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxOuputSpeedRegister = gpio_bank + RegisterOffsets::OutputSpeedRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxPullUpPullDownRegister = gpio_bank + RegisterOffsets::PullUpPullDownRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxInputDataRegister = gpio_bank + RegisterOffsets::InputDataRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxOutputDataRegister = gpio_bank + RegisterOffsets::OutputDataRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxBitSetResetLowRegister = gpio_bank + RegisterOffsets::BitSetResetLowRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxBitSetResetHighRegister = gpio_bank + RegisterOffsets::BitSetResetHighRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxLockRegister = gpio_bank + RegisterOffsets::LockRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxAlternateFunctionHighRegister = gpio_bank + RegisterOffsets::AlternateFunctionHighRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxAlternateFunctionLowRegister = gpio_bank + RegisterOffsets::AlternateFunctionLowRegisterOffset;
	static constexpr GPIOxRegisterType bitPosition = (1UL << (pinNumber -1));
        rcc::RCCRegisterType bankEnable;



};


#endif /* GPIO_H_ */