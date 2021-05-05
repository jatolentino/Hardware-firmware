#include <stdint.h>
//#include <stdio.h>
int main(void)
{
    /* Loop forever */
	uint32_t *pClk = (uint32_t*)0x40023830;  // clock register
	uint32_t *pPortD = (uint32_t*)0x40020C00; // port moude register
	uint32_t *pPortDout = (uint32_t*)0x40020C14; // port to output

	// 1. Turning the clock on bus HBN1
	*pClk |= 0x08; // bitwise flushleft operator, no need to user masked value, pClk | (1<<4)
	
	// 2. Setting the mode port the GPIOD
	*pPortD &= 0xFCFFFFFF;
	*pPortD |= 0x01000000;
	
	// 3. Configure to ouput mode
	*pPortDout |= 0x1000;
	//for(;;);
	while(1);
}
