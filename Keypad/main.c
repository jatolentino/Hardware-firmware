#include <stdint.h>
#include <stdio.h>

int main(main)
{
  //Adding the peripherla registers addresses
  uint32_t volatile *const pGpioModeReg = (uint32_t*)0x40020C00;
  uint32_t volatile *const pInPutDataReg = (uint32_t*)0x40020C00 + 0x10;
  uint32_t volatile *cohst pOutDataReg = (uint32_t*)0x40020C00 + 0x14;
  uint32_t volatile *const pClockCtrlReg = (uint32_t*)0x40023800 + 0x30;
  uint32_t volatile *const pPullupDownReg = (uint32_t*)0x40020C00 + 0x0C;
  
  // Enable the clock of the GPIOD peripheral
  *pClockCtrlReg |= (1<<3);
  
  // Configure the port mode register as GENERAL PURPOSE OUTPUT MODE, p. 281
  // FOR THE ROWS
  // PD3      PD2     PD1     PD1
  //MODER3  MODER2  MODER1  MODER0
  //01      01      01      01 = 0x55
  *GpioModeReg &= ~(0xFF);  //set to 0
  *GpioModeReg |= 0x55;
  
  
  // Configure the port mode as INPUT (RESET STATE), p.281
  // FOR THE COLUMNS
  //PD8      PD9      PD10     PD11
  //MODER8  MODER9  MODER10  MODER11
  // 00      00      00        00
  *GpioModereg &= ~(0xFF<<16);
  
  // Set rows to HIGH, binary is 1111 = 0x0F
  *pOutDataReg |= 0x0F;
  
  // Set 1st ROW to low
  *pOutDataReg &= 0;  // *pOutDataReg &= ~(1<<0); 
  
  // Scan the columns
  // Check the inputs if high
  if (!(0x40020C10 & (1 << 8))){
     printf("1\n");
  }
  if (!(0x40020C10 & (1 << 9))){
     printf(2"\n");
  }
  if (!(0x40020C10 & (1 << 10))){
     printf("3\n");
  }
  if (!(0x40020C10 & (1 << 11))){
     printf("A\n");
  }
  
  
  
  
  
  
   
}
