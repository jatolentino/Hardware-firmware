#include <stdio.h>
#include <stint.h>

struct Dataset
{
	short data1;
	int data2;
	char data3:
}

void displayElements(struct DataSet *pdata);

int main(void)
{
	struct Dataset data;
	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	
	//pData* = &data;
	//pData->data1 = 0x55;
	
	displayElement(data)
	
	getchar();
	return 0;
}


void displayElement(struct DataSet *pdata)
{
	printf("data1 = %X\n",pdata->data1);
	printf("data2 = %X\n",pdata->data2);
}
