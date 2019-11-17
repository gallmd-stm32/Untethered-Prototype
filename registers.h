/*
 * registers.h
 *
 *  Created on: Oct 4, 2018
 *      Author: matt
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_


#include <stdint.h>

typedef uint32_t Register32Bit;
namespace stm32fxx
{


namespace registers
{


	//GPIOA Registers
	constexpr Register32Bit GPIO_A = 0x40020000U;
	constexpr Register32Bit GPIOA_MODER = 	GPIO_A + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOA_OTYPER = 	GPIO_A + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOA_OSPEEDR = 	GPIO_A + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOA_PUPDR = 	GPIO_A + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOA_IDR = 		GPIO_A + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOA_ODR = 		GPIO_A + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOA_BSRRL = 	GPIO_A + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOA_BSRRH = 	GPIO_A + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOA_LCKR = 	GPIO_A + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOA_AFR1 = 	GPIO_A + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOA_AFR2 = 	GPIO_A + 0x24U; //GPIO alternate function register 2

	//GPIOB Registers
	constexpr Register32Bit GPIO_B = 0x40020400U;
	constexpr Register32Bit GPIOB_MODER = 	GPIO_B + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOB_OTYPER = 	GPIO_B + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOB_OSPEEDR = 	GPIO_B + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOB_PUPDR = 	GPIO_B + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOB_IDR = 		GPIO_B + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOB_ODR = 		GPIO_B + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOB_BSRRL = 	GPIO_B + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOB_BSRRH = 	GPIO_B + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOB_LCKR = 	GPIO_B + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOB_AFR1 = 	GPIO_B + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOB_AFR2 = 	GPIO_B + 0x24U; //GPIO alternate function register 2

	//GPIOC Registers
	constexpr Register32Bit GPIO_C = 0x40020800U;
	constexpr Register32Bit GPIOC_MODER = 	GPIO_C + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOC_OTYPER = 	GPIO_C + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOC_OSPEEDR = 	GPIO_C + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOC_PUPDR = 	GPIO_C + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOC_IDR = 		GPIO_C + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOC_ODR = 		GPIO_C + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOC_BSRRL = 	GPIO_C + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOC_BSRRH = 	GPIO_C + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOC_LCKR = 	GPIO_C + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOC_AFR1 = 	GPIO_C + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOC_AFR2 = 	GPIO_C + 0x24U; //GPIO alternate function register 2

	//GPIOD Registers
	constexpr Register32Bit GPIO_D = 0x40020C00U;
	constexpr Register32Bit GPIOD_MODER = 	GPIO_D + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOD_OTYPER = 	GPIO_D + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOD_OSPEEDR = 	GPIO_D + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOD_PUPDR = 	GPIO_D + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOD_IDR = 		GPIO_D + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOD_ODR = 		GPIO_D + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOD_BSRRL = 	GPIO_D + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOD_BSRRH = 	GPIO_D + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOD_LCKR = 	GPIO_D + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOD_AFR1 = 	GPIO_D + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOD_AFR2 = 	GPIO_D + 0x24U; //GPIO alternate function register 2

	//GPIOE Registers
	constexpr Register32Bit GPIO_E = 0x40021000U;
	constexpr Register32Bit GPIOE_MODER = 	GPIO_E + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOE_OTYPER = 	GPIO_E + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOE_OSPEEDR = 	GPIO_E + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOE_PUPDR = 	GPIO_E + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOE_IDR = 		GPIO_E + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOE_ODR = 		GPIO_E + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOE_BSRRL = 	GPIO_E + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOE_BSRRH = 	GPIO_E + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOE_LCKR = 	GPIO_E + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOE_AFR1 = 	GPIO_E + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOE_AFR2 = 	GPIO_E + 0x24U; //GPIO alternate function register 2

	//GPIOF Registers
	constexpr Register32Bit GPIO_F = 0x40021400U;
	constexpr Register32Bit GPIOF_MODER = 	GPIO_F + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOF_OTYPER = 	GPIO_F + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOF_OSPEEDR = 	GPIO_F + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOF_PUPDR = 	GPIO_F + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOF_IDR = 		GPIO_F + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOF_ODR = 		GPIO_F + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOF_BSRRL = 	GPIO_F + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOF_BSRRH = 	GPIO_F + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOF_LCKR = 	GPIO_F + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOF_AFR1 = 	GPIO_F + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOF_AFR2 = 	GPIO_F + 0x24U; //GPIO alternate function register 2

	//GPIOG Registers
	constexpr Register32Bit GPIO_G = 0x40021800U;
	constexpr Register32Bit GPIOG_MODER = 	GPIO_G + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOG_OTYPER = 	GPIO_G + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOG_OSPEEDR = 	GPIO_G + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOG_PUPDR = 	GPIO_G + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOG_IDR = 		GPIO_G + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOG_ODR = 		GPIO_G + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOG_BSRRL = 	GPIO_G + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOG_BSRRH = 	GPIO_G + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOG_LCKR = 	GPIO_G + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOG_AFR1 = 	GPIO_G + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOG_AFR2 = 	GPIO_G + 0x24U; //GPIO alternate function register 2

	//GPIOH Registers
	constexpr Register32Bit GPIO_H = 0x40021C00U;
	constexpr Register32Bit GPIOH_MODER = 	GPIO_H + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOH_OTYPER = 	GPIO_H + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOH_OSPEEDR = 	GPIO_H + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOH_PUPDR = 	GPIO_H + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOH_IDR = 		GPIO_H + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOH_ODR = 		GPIO_H + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOH_BSRRL = 	GPIO_H + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOH_BSRRH = 	GPIO_H + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOH_LCKR = 	GPIO_H + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOH_AFR1 = 	GPIO_H + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOH_AFR2 = 	GPIO_H + 0x24U; //GPIO alternate function register 2

	//GPIOI Registers
	constexpr Register32Bit GPIO_I = 		0x40022000U;
	constexpr Register32Bit GPIOI_MODER = 	GPIO_I + 0x00U; //GPIO port mode register
	constexpr Register32Bit GPIOI_OTYPER = 	GPIO_I + 0x04U; //GPIO port output type register
	constexpr Register32Bit GPIOI_OSPEEDR = 	GPIO_I + 0x08U; //GPIO port output speed register
	constexpr Register32Bit GPIOI_PUPDR = 	GPIO_I + 0x0CU; //GPIO port pull-up/pull-down register
	constexpr Register32Bit GPIOI_IDR = 		GPIO_I + 0x10U; //GPIO port input data register
	constexpr Register32Bit GPIOI_ODR = 		GPIO_I + 0x14U; //GPIO port output data register
	constexpr Register32Bit GPIOI_BSRRL = 	GPIO_I + 0x18U; //GPIO port bit set/reset low register
	constexpr Register32Bit GPIOI_BSRRH = 	GPIO_I + 0x1AU; //GPIO port bit set/reset high register
	constexpr Register32Bit GPIOI_LCKR = 	GPIO_I + 0x1CU; //GPIO port configuration lock register
	constexpr Register32Bit GPIOI_AFR1 = 	GPIO_I + 0x20U; //GPIO alternate function register 1
	constexpr Register32Bit GPIOI_AFR2 = 	GPIO_I + 0x24U; //GPIO alternate function register 2

	//USART1 Registers
	constexpr Register32Bit USART1_ 		= 0x40011000U;
	constexpr Register32Bit USART1_SR 		= USART1_;
	constexpr Register32Bit USART1_DR 		= USART1_ + 0x04U; //USART data register
	constexpr Register32Bit USART1_BRR 		= USART1_ + 0x08U; //USART Baud rate register
	constexpr Register32Bit USART1_CR1 		= USART1_ + 0x0CU; //USART control register 1
	constexpr Register32Bit USART1_CR2 		= USART1_ + 0x10U; //USART control register 2
	constexpr Register32Bit USART1_CR3 		= USART1_ + 0x14U; //USART control register 3
	constexpr Register32Bit USART1_GTPR 	= USART1_ + 0x18U; //USART guard time and pre-scaler register

	//RCC Registers
	constexpr Register32Bit RCC_ = 0x40021000U;
	constexpr Register32Bit RCC_CR = RCC_;
	constexpr Register32Bit RCC_CFGR = RCC_ + 0x04U;
	constexpr Register32Bit RCC_CIR = RCC_ + 0x08U;
	constexpr Register32Bit RCC_APB2RSTR = RCC_ + 0x0CU;
	constexpr Register32Bit RCC_APB1RSTR = RCC_ + 0x10U;
	constexpr Register32Bit RCC_AHBENR = RCC_ + 0x14U;
	constexpr Register32Bit RCC_APB2ENR = RCC_ + 0x18U;
	constexpr Register32Bit RCC_APB1ENR = RCC_ + 0x1CU;
	constexpr Register32Bit RCC_BDCR = RCC_ + 0x20U;
	constexpr Register32Bit RCC_CSR = RCC_ + 0x24U;
	constexpr Register32Bit RCC_AHBSTR = RCC_ + 0x28U;
	constexpr Register32Bit RCC_CFGR2 = RCC_ + 0x2CU;



}

namespace bits
{

	constexpr uint32_t BIT0 	= 1UL;
	constexpr uint32_t BIT1 	= (1UL << 1);
	constexpr uint32_t BIT2 	= (1UL << 2);
	constexpr uint32_t BIT3 	= (1UL << 3);
	constexpr uint32_t BIT4 	= (1UL << 4);
	constexpr uint32_t BIT5 	= (1UL << 5);
	constexpr uint32_t BIT6 	= (1UL << 6);
	constexpr uint32_t BIT7 	= (1UL << 7);
	constexpr uint32_t BIT8 	= (1UL << 8);
	constexpr uint32_t BIT9 	= (1UL << 9);
	constexpr uint32_t BIT10 	= (1UL << 10);
	constexpr uint32_t BIT11 	= (1UL << 11);
	constexpr uint32_t BIT12 	= (1UL << 12);
	constexpr uint32_t BIT13 	= (1UL << 13);
	constexpr uint32_t BIT14 	= (1UL << 14);
	constexpr uint32_t BIT15 	= (1UL << 15);
        constexpr uint32_t BIT16 	= (1UL << 16);
        constexpr uint32_t BIT17 	= (1UL << 17);
        constexpr uint32_t BIT18 	= (1UL << 18);
        constexpr uint32_t BIT19 	= (1UL << 19);
        constexpr uint32_t BIT20 	= (1UL << 20);
        constexpr uint32_t BIT21 	= (1UL << 21);
        constexpr uint32_t BIT22 	= (1UL << 22);
        constexpr uint32_t BIT23 	= (1UL << 23);
        constexpr uint32_t BIT24 	= (1UL << 24);
        constexpr uint32_t BIT25 	= (1UL << 25);
        constexpr uint32_t BIT26 	= (1UL << 26);
        constexpr uint32_t BIT27 	= (1UL << 27);
        constexpr uint32_t BIT28 	= (1UL << 28);
        constexpr uint32_t BIT29 	= (1UL << 29);
        constexpr uint32_t BIT30 	= (1UL << 30);
        constexpr uint32_t BIT31 	= (1UL << 31);








}

}
#endif /* REG_ACCESS_H_ */