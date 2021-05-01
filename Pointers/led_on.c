#include <stdint.h>
//#include <stdio.h>
int main(void)
{
    /* Loop forever */
	uint32_t *pClk = (uint32_t*)0x40023830;
	uint32_t *pPortD = (uint32_t*)0x40020C00;
	uint32_t *pPortDout = (uint32_t*)0x40020C14;

