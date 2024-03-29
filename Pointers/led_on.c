#include <stdint.h>
//#include <stdio.h>

void my_func(void);
int main(void)
{    /* Loop forever */
	uint32_t *pClk = (uint32_t*)0x40023830;  // clock register
	uint32_t *pPortD = (uint32_t*)0x40020C00; // port moude register
	uint32_t *pPortDout = (uint32_t*)0x40020C14; // port to output

	// 1. Turning the clock on bus HBN1
	*pClk |= 0x08; // bitwise flushleft operator, no need to user masked value, pClk |= (1<<3)
	
	// 2. Setting the mode port the GPIOD
	*pPortD &= 0xFCFFFFFF; // pPortD &= ~(3<<24) bitwise flush left
	*pPortD |= 0x01000000; // pPortD |= (1<<24)
	
	// 3. Configure to ouput mode
	*pPortDout |= 0x1000;  // pPortDout |= (1<<12)
	//for(;;);  
	while(1);
}

void my_func(void){
	printf("Hit enter to quit");
	if(getchar() != '\n'){
	return 0;}
	getchar();
}
