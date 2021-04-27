#include<stdio.h>

int main(void)
{
	long long int dat = 0xa0b3690605401601; 		// input hex data
	short* pAdd = (short*)&dat;				// assign 2 bits of storage per address and stored is pAdd pointer

	printf("\n address is %p", pAdd);			// print the 1st pointer address
	*pAdd = 255;						// modify 1st data address "01" with 255dec or ffhex
	printf("\n address is %p and value %x", pAdd, *pAdd);	// print the first address and its new value
	
	pAdd = pAdd + 1;					// switch in 1 byte to the next address

	printf("\n address is %p and value %x", pAdd, *pAdd);	// print the next address and its value which hasn't changed
	
	pAdd = pAdd + 1;					// switch in 1 byte to the next address again

	printf("\n address is %p and value %x", pAdd, *pAdd);   // once more, print the next address and its value which hasn't changed

	return 0;
}

