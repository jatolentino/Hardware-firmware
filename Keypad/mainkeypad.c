#include <stdint.h>
#include <stdio.h>

void delay(){
  	for(uint32_t i=0; i<300000 ; i++);
}

int main(main){
	//Adding the peripherla registers addresses
	uint32_t volatile *const pGpioModeReg = (uint32_t*)0x40020C00; // choosing the PIN mode
	uint32_t volatile *const pInPutDataReg = (uint32_t*)0x40020C00 + 0x10; // configure register as input 
	uint32_t volatile *const pOutDataReg = (uint32_t*)0x40020C00 + 0x14; //configure register as output
	uint32_t volatile *const pClockCtrlReg = (uint32_t*)0x40023800 + 0x30; // set clock register AHN1EN
	uint32_t volatile *const pPullupDownReg = (uint32_t*)0x40020C00 + 0x0C; // configure the pull-up register

	// Enable the clock of the GPIOD peripheral
	*pClockCtrlReg |= (1<<3);

	// Configure the port mode register as GENERAL PURPOSE OUTPUT MODE, p. 281
	// FOR THE ROWS
	// PD3      PD2     PD1     PD1
	//MODER3  MODER2  MODER1  MODER0
	//01      01      01      01 = 0x55
	*pGpioModeReg &= ~(0xFF);  //set to 0
	*pGpioModeReg |= 0x55;

	// Configure the port mode as INPUT (RESET STATE), p.281
	// FOR THE COLUMNS
	//PD8      PD9      PD10     PD11
	//MODER8  MODER9  MODER10  MODER11
	// 00      00      00        00
	*pGpioModereg &= ~(0xFF<<16);

	while(1){
		// Set rows to HIGH, binary is 1111 = 0x0F
		*pOutDataReg |= 0x0F;

		// Set 1st ROW to low
		*pOutDataReg &= ~(1<<0); //PD0

		// Scan the columns
		// Check the inputs if high
		if (!(pInPutDataReg & (1 << 8))){  //PD8
		  delay();
		  printf("1\n");
		}
		if (!(pInPutDataReg & (1 << 9))){  //PD9
		  delay();
		  printf("2\n");
		}
		if (!(pInPutDataReg & (1 << 10))){  //PD10
		  delay();
		  printf("3\n");
		}
		if (!(pInPutDataReg & (1 << 11))){  //PD11
		  delay();
		  printf("A\n");
		}

		//Make the 2nd row low and all rows high
		*pOutDataReg |= 0x0F;
		*pOutDataReg &= ~(1<<1);  //PD1
		if (!(pInPutDataReg & (1 << 8))){ //PD8
		  delay();
		  printf("4\n");
		}
		if (!(pInPutDataReg & (1 << 9))){ //PD9
		  delay();
		  printf("5\n");
		}
		if (!(pInPutDataReg & (1 << 10))){  //PD10
		  delay();
		  printf("6\n");
		}
		if (!(pInPutDataReg & (1 << 11))){  //PD11
		  delay();
		  printf("B\n");
		}

		//Make the 3rd row low and all rows high
		*pOutDataReg |= 0x0F;   //PD2
		*pOutDataReg &= ~(1<<2);
		if (!(pInPutDataReg & (1 << 8))){ //PD8
		  delay();
		  printf("7\n");
		}
		if (!(pInPutDataReg & (1 << 9))){ //PD9
		  delay();
		  printf("8\n");
		}
		if (!(pInPutDataReg & (1 << 10))){  //PD10
		  delay();
		  printf("9\n");
		}
		if (!(pInPutDataReg & (1 << 11))){  //PD11
		  delay();
		  printf("C\n");
		}

		//Make the 3rd row low and all rows high
		*pOutDataReg |= 0x0F;
		*pOutDataReg &= ~(1<<3);  //PD3
		if (!(pInPutDataReg & (1 << 8))){ //PD8
		  delay();
		  printf("*\n");
		}
		if (!(pInPutDataReg & (1 << 9))){ //PD9
		  delay();
		  printf("0\n");
		}
		if (!(pInPutDataReg & (1 << 10))){  //PD10
		  delay();
		  printf("#\n");
		}
		if (!(pInPutDataReg & (1 << 11))){  //PD11
		  delay();
		  printf("D\n");
		}
	}
}
