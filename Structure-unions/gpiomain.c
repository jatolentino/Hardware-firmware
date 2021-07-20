#include "main.h"

int main(void)
{
	RCC_AHB1NR_t volatile *const pClk = (*RCC_AHB1NR_t) 0x40023830;
	GPIOx_MODE_t volatile *const pPortD = (*GPIOx_MODE_t) 0x40020C00;
	GPIOx_MODE_t volatile *const pPortDout = (*GPIOx_MODE_t) 0x40020C14;

}
