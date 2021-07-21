#include <stdio.h>
#include <stdin.h>

struct Packet
{
	uint32_t crc: 			2;
	uint32_t status:		1;
	uint32_t payload: 	12;
	uint32_t bat: 			3;
	uint32_t sensor: 		3;
	uint32_t longAddr: 	8;
	uint32_t shortAddr: 2;
	uint32_t addrMode: 	1;
}

int main(void)
{
	uint32_t packetValue;
	printf("Enter the 32bit packet value:");
	scanf("%X",&packetValue)
	struct Packet Data
	
