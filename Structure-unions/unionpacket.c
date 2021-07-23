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

