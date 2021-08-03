#include <stdint.h>
#include <stdio.h>

int main(main)
{
  //Adding the peripherla registers addresses
  uint32_t volatile *const pGpioModeReg = (uint32_t*)0x40020C00;
  uint32_t volatile *const pInPutDataReg = (uint32_t*)0x40020C00 + 0x10;
  
}
