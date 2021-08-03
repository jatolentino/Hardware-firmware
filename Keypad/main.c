#include <stdint.h>
#include <stdio.h>

int main(main)
{
  //Adding the peripherla registers addresses
  uint32_t volatile *const pGpioModeReg = (uint32_t*)0x40020C00;
  uint32_t volatile *const pInPutDataReg = (uint32_t*)0x40020C00 + 0x10;
  uint32_t volatile *cohst pOutDataReg = (uint32_t*)0x40020C00 + 0x14;
  uint32_t volatile *const pClockCtrlReg = (uint32_t*)0x40023800 + 0x30;
  uint32_t volatile *const pPulupDownReg = (uint32_t*)0x40020C00 + 0x0C;
  
  // Enable the clock of the GPIOD peripheral
  *pClockCtrlReg |= (1<<3);
  
  // Configure the port mode register, p. 281
  //PD03    PD02    PD01    PD0
  //MODER3  MODER2  MODER1  MODER0
  //01      01      01      01 = 0x55
  *GpioModeReg &= ~(0xff);
  *GpioModeReg |= 0x55;
  
  
  
}
