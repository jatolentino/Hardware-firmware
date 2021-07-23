#include<stdio.h>
#include<stdint.h>

union Packet
{
	uint32_t packetValue;
	struct
	{
		uint32_t crc: 			2;
		uint32_t status:		1;
		uint32_t payload: 	12;
		uint32_t bat: 			3;
		uint32_t sensor: 		3;
		uint32_t longAddr: 	8;
		uint32_t shortAddr: 2;
		uint32_t addrMode: 	1;
	}packetFields;
}

int main(void)
{
	union Packet Data;
	printf("Enter the 32bit packet value:");
	scanf("%X",&Data.packetValue)

	printf("Scanning each value");
	printf("crc %x\n",Data.packetFields.crc);
	printf("status %x\n",Data.packetFields.status);
	printf("payload %x\n",Data.packetFields.payload);
	printf("bat %x\n",Data.packetFields.bat);
	printf("sensor %x\n",Data.packetFields.sensor);
	printf("longAddr %x\n",Data.packetFields.longAddr);
	printf("shortAddr %x\n",Data.packetFields.shortAddr);
	printf("addrMode %x\n",Data.packetFields.addrMode);
	
	printf("size of the union in %I64\n",sizeof(packet));
	
	while(getchar()!=0);
	getchat();
	return 0;
}


