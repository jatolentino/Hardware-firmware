#include <stdint.h>
#include <stdio.h>

void delay(){
  for(uint32_t i=0; i<300000 ; i++);
}
int main(main)
{
  //Adding the peripherla registers addresses
  uint32_t volatile *const pGpioModeReg = (uint32_t*)0x40020C00;
  uint32_t volatile *const pInPutDataReg = (uint32_t*)0x40020C00 + 0x10;
  uint32_t volatile *const pOutDataReg = (uint32_t*)0x40020C00 + 0x14;
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
  
  
  while(1){
    // Set rows to HIGH, binary is 1111 = 0x0F
    *pOutDataReg |= 0x0F;

    // Set 1st ROW to low
    *pOutDataReg &= ~(1<<0); //PD0

    // Scan the columns
    // Check the inputs if high
    if (!(0x40020C10 & (1 << 8))){  //PD8
      delay(); 
      printf("1\n");
    }
    if (!(0x40020C10 & (1 << 9))){  //PD9
      delay(); 
      printf(2"\n"); 
    }
    if (!(0x40020C10 & (1 << 10))){  //PD10
      delay(); 
      printf("3\n");
    }
    if (!(0x40020C10 & (1 << 11))){  //PD11
      delay();
      printf("A\n");
    }

    //Make the 2nd row low and all rows high
    *pOutDataReg |= 0x0F; 
    *pOutDataReg &= ~(1<<1);  //PD1
    if (!(0x40020C10 & (1 << 8))){
      delay();
      printf("4\n");
    }
    if (!(0x40020C10 & (1 << 9))){
      delay(); 
      printf(5"\n");
    }
    if (!(0x40020C10 & (1 << 10))){
      delay(); 
      printf("6\n");
    }
    if (!(0x40020C10 & (1 << 11))){
      delay(); 
      printf("B\n");
    }

    //Make the 3rd row low and all rows high
    *pOutDataReg |= 0x0F;   //PD2
    *pOutDataReg &= ~(1<<2);
    if (!(0x40020C10 & (1 << 8))){
      delay();
      printf("7\n");
    }
    if (!(0x40020C10 & (1 << 9))){
      delay(); 
      printf(8"\n");
    }
    if (!(0x40020C10 & (1 << 10))){
      delay(); 
      printf("9\n");
    }
    if (!(0x40020C10 & (1 << 11))){
      delay(); 
      printf("C\n");
    }

    //Make the 3rd row low and all rows high
    *pOutDataReg |= 0x0F;
    *pOutDataReg &= ~(1<<3)  //PD3
    if (!(0x40020C10 & (1 << 8))){
      delay();
      printf("*\n");
    }
    if (!(0x40020C10 & (1 << 9))){
      delay(); 
      printf("0\n");
    }
    if (!(0x40020C10 & (1 << 10))){
      delay(); 
      printf("#\n");
    }
    if (!(0x40020C10 & (1 << 11))){
      delay(); 
      printf("D\n");
    } 
  
  }
}
