#include<stdio.h>

int main(void)
{
	long long int dat = 0xa0b3690605401601;
	short* pAdd = (short*)&dat;// 0x0000000000401601;

	printf("\n address is %p", pAdd);
	*pAdd = 255;
	printf("\n address is %p and value %x", pAdd, *pAdd);
	
	pAdd = pAdd + 1;

	printf("\n address is %p and value %x", pAdd, *pAdd);

}

