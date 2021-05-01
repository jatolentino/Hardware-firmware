#include <stdint.h>
//#include <stdio.h>
int main(void)
{
    /* Loop forever */
	uint32_t *pClk = (uint32_t*)0x40023830;
	uint32_t *pPortD = (uint32_t*)0x40020C00;
	uint32_t *pPortDout = (uint32_t*)0x40020C14;

	// 1. Turning the clock on
	*pClk |= 0x08;
	*pPortD &= 0xFCFFFFFF;
	*pPortD |= 0x01000000;
	*pPortDout |= 0x1000;
	
}
