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

	Data.crc = packetValue & 0x3;
	Data.status = (packetValue >> 2) & 0x1;
	Data.payload = (packetValue >> 3) & 0xFFF;
	Data.bat = (packetValue >> 15) & 0x7;
	Data.sensor = (packetValue >> 18) & 0x7;
	Data.longAddr = (packetValue >> 21) & 0xFF;
	Data.shortaddr = (packetValue >> 29) & 0x3;
	Data.addMode = (packetValue >> 31) & 0x1;
	
	printf("Scanning each value");
	printf("crc %x\n",Data.crc);
	printf("status %x\n",Data.status);
	printf("payload %x\n",Data.payload);
	printf("bat %x\n",Data.bat);
	printf("sensor %x\n",Data.sensor);
	printf("longAddr %x\n",Data.longAddr);
	printf("shortAddr %x\n",Data.shortAddr);
	printf("addrMode %x\n",Data.addrMode);
}
