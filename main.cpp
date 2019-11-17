/* Includes */
#include "stm32f4xx.h"
#include "gpio.h"
#include "i2c.h"
#include "usart.h"
#include "gpio_config.h"
#include "circular_buffer.h"
#include "adc.h"

//TODO usartTXBuf should be called usartRXBuf



/* Private function prototypes */
void Delay(__IO uint32_t nCount);
void writeVoltage(uint8_t rawAnalogData);


int main(void)
{
  
  Delay(0xFFFF);
  const GPIO<GPIOxBaseRegisters::GPIO_B,
              PINS::PIN12,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>greenLED;

   __enable_irq();

  I2CMaster i2c(I2C::BaseRegisters::I2C1_Base);

  util::circular_buffer<uint8_t> usartTXBuf(50);
  util::circular_buffer<uint8_t> *txPtr;
  txPtr = &usartTXBuf;
  

  USART::Usart myUsart1(USART::BaseRegisters::USART1Base, txPtr);
  ADC_INT test(ADC_MDG::BaseRegisters::ADC1_MDG);

  //setup i2c Display
  uint8_t displayAddress = 0xE4U;
  uint8_t clearDisplay[2] = {0x7C, 0x2D};
  uint8_t testText[7] = {'a','b','c','d','e','f','g'};
  uint8_t testText2[] = "12345678901234561234567890123456";
  
//  uint8_t setBacklight[7] = {0x7C,0x2D,0x7C,0x18,0xFF,0xFF,0x00};
  uint8_t setBacklight[7] = {'|','-','|','+',0xFF,0x00,0x00};

  i2c.sendBytes(setBacklight,displayAddress,7);
  Delay(0xFFF);
//  i2c.sendBytes(testText2,displayAddress,32);


 
  while(1){
     uint8_t data;
     uint8_t analogData[3];
     analogData[0] = 0x7C;
     analogData[1] = 0x2D;
     uint32_t rawData;

     rawData = test.readValue();
     

       //8 bit data, 3.3V full range = 0.0128 Volts/Bit
     constexpr float voltageStep = 0.0128906;
     float voltage = rawData * voltageStep;
     uint8_t firstDigit = voltage;
     analogData[2] = firstDigit+48;

//     i2c.sendBytes(clearDisplay, displayAddress, 2);
     i2c.sendBytes(analogData, displayAddress, 3);
    
     if(!usartTXBuf.empty()){
  
      data = usartTXBuf.get();



      myUsart1.sendBytes(data);
      greenLED.toggle();

     }
     Delay(0xFFFFF);
     

    
  }
  

  return 0;

}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}


void writeVoltage(uint8_t rawAnalogData)
{

  //8 bit data, 3.3V full range = 0.0128 Volts/Bit
  constexpr float voltageStep = 0.0128906;
  float voltage = rawAnalogData * voltageStep;
  uint8_t firstDigit = voltage;
  Delay(0xF);



}
