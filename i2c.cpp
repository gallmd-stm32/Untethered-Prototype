/*
 * i2c.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: matt
 */




#include "i2c.h"

I2CMaster::I2CMaster(I2C::BaseRegisterType baseRegister)
{

  //Program the peripheral input clock in the I2C_CR2 register in order to generate the correct timings
  reg_access<rcc::RCCRegisterType, 
              rcc::RCCRegisterType, 
              rcc::BaseRegisters::RccBaseRegister+rcc::RccAPB1EnableRegister::RegisterOffset, 
              rcc::RccAPB1EnableRegister::I2C1Enable>::reg_or();

  //setup pins for I2C
  const GPIO<GPIOxBaseRegisters::GPIO_B,
  	  PINS::PIN6,
  	  GpioModes::AlternateFunction,
  	  OutputTypes::OpenDrain,
  	  OutputSpeed::HighSpeed,
  	  PullUpPullDown::NoPullUpPullDown,
  	  AlternateFunction::AF4>sdaPin;

  const GPIO<GPIOxBaseRegisters::GPIO_B,
  	  PINS::PIN7,
  	  GpioModes::AlternateFunction,
  	  OutputTypes::OpenDrain,
  	  OutputSpeed::HighSpeed,
  	  PullUpPullDown::NoPullUpPullDown,
          AlternateFunction::AF4>sclPin;

  clockControlRegister = baseRegister + I2C::ClockControlRegister::RegiserOffset;
  controlRegister1 = baseRegister + I2C::ControlRegister1::RegisterOffset;
  controlRegister2 = baseRegister + I2C::ControlRegister2::RegisterOffset;
  dataRegister = baseRegister + I2C::DataRegister::RegisterOffset;
  filterRegister = baseRegister + I2C::FilterRegister::RegisterOffset;
  ownAddressRegister = baseRegister + I2C::OwnAddressRegister::RegisterOffset;
  ownAddressRegister2 = baseRegister + I2C::OwnAddressRegister2::RegisterOffset;
  statusRegister1 = baseRegister + I2C::StatusRegister1::RegisterOffset;
  statusRegister2 = baseRegister + I2C::StatusRegister2::RegisterOffset;
  triseRegister = baseRegister + I2C::TRiseRegiser::RegisterOffset;

  //program the I2C_CR1 register to enable the peripheral
  dynamic_access<I2C::BaseRegisterType, I2C::ControlRegister2Type>::reg_or(controlRegister2,
                 I2C::ControlRegister2::BufferInterruptEnable |
                 I2C::ControlRegister2::ErrorInterruptEnable |
                 I2C::ControlRegister2::EventInterruptEnable);

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);               
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQn; //TIM4 IRQ Channel
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//Preemption Priority
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //Sub Priority
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitTypeDef NVIC_InitStructure2;

  NVIC_InitStructure2.NVIC_IRQChannel = I2C1_ER_IRQn; //TIM4 IRQ Channel
  NVIC_InitStructure2.NVIC_IRQChannelPreemptionPriority = 0;//Preemption Priority
  NVIC_InitStructure2.NVIC_IRQChannelSubPriority = 0; //Sub Priority
  NVIC_InitStructure2.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure2);

  I2CMaster::registerInterrupt();


  dynamic_access<I2C::BaseRegisterType, I2C::ControlRegister1Type>::reg_not(controlRegister1,
    		I2C::ControlRegister1::SoftwareReset);

  //set frequency bits
  dynamic_access<I2C::BaseRegisterType, I2C::ControlRegister2Type>::reg_or(controlRegister2, 0x10U);

  //configure the clock control registers
  dynamic_access<I2C::BaseRegisterType, I2C::ClockControlRegisterType>::reg_or(0x4000541CU, 0x50U);

  //configure the rise time register
  dynamic_access<I2C::BaseRegisterType, I2C::TRiseRegisterType>::reg_or(triseRegister, 0x11U);

  //enable ACK in CR1
  dynamic_access<I2C::BaseRegisterType, uint16_t>::reg_or(controlRegister1,
    		I2C::ControlRegister1::ACK);

  //Enable peripheral in CR1
  dynamic_access<I2C::BaseRegisterType, I2C::ControlRegister1Type>::reg_or(controlRegister1,
    		I2C::ControlRegister1::PeripheralEnable);


}



int I2CMaster::sendBytes(uint8_t * sendBuffer, uint8_t address, uint8_t messageLength)
{

	bytesSent = 0;
	dataSent = false;

	send_buf = sendBuffer;
	slaveAddress = address;
        bytesToSend = messageLength;

    dynamic_access<I2C::BaseRegisterType, uint16_t>::reg_or(controlRegister1,
    		I2C::ControlRegister1::ACK);

	//Set Start Bit
	//0x40005400U
	dynamic_access<I2C::BaseRegisterType, I2C::ControlRegister1Type> ::reg_or(controlRegister1, I2C::ControlRegister1::Start);




	return 1;
}

void I2CMaster::EV_handler()
{

	uint16_t status;
	uint16_t temp;

	//0x40005414
	status = dynamic_access<I2C::BaseRegisterType, uint16_t>::reg_get(statusRegister1);
	reg_access<GPIOxRegisterType, GPIOxRegisterType, (GPIOxBaseRegisters::GPIO_B + RegisterOffsets::OutputDataRegisterOffset), stm32fxx::bits::BIT12>::reg_xor();

	 if(status & I2C::StatusRegister1::StartBit){

		 //send address
		 //0x40005410
		 dynamic_access<I2C::BaseRegisterType, uint8_t>::reg_set(dataRegister, slaveAddress);

	 }
        
        //address sent, check status registers to clear ADDR bit
	if(status & I2C::StatusRegister1::Address){

		//read SR2
		//0x40005414
		status = dynamic_access<I2C::BaseRegisterType, uint16_t>::reg_get(statusRegister1);

		//0x40005418
		temp = 	dynamic_access<I2C::BaseRegisterType, uint16_t>::reg_get(statusRegister2);

	}
        

        //send data
	if((status & I2C::StatusRegister1::TransmitEmpty)){ 	//& (status & I2C::StatusRegister1::ByteTransferFinished)

		if((bytesSent <= bytesToSend) & (!dataSent)){

			//0x40005410
			dynamic_access<I2C::BaseRegisterType, uint8_t>::reg_set(dataRegister, *(send_buf+bytesSent));
			bytesSent++;

		}

		if((bytesSent > bytesToSend) & (!dataSent)){

			dataSent = true;
			//0x40005400
			dynamic_access<I2C::BaseRegisterType, uint16_t>::reg_or(I2CMaster::controlRegister1, I2C::ControlRegister1::Stop);

		}
	}


}

void I2CMaster::ER_handler()
{

	dynamic_access<I2C::BaseRegisterType, I2C::ControlRegister1Type>::reg_or(I2CMaster::controlRegister1, I2C::ControlRegister1::SoftwareReset);


}

void I2CMaster::registerInterrupt()
{

  handlerPointers[I2C1_IDX] = this;
   


}

void I2CMaster::handleInterrupts(int interruptType){

  I2CMaster::EV_handler();

}




