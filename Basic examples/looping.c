#include <stdio.h>
#include <stdint.h>
void wait_input(void);
int main(void)
{
	int32_t start_num, end_num, even;
	printf("Enter starting and ending memebers(give space between 2 nos):");
	scanf("%d %d", &start_num,&end_num)
	
	if(end_num < start_num){
		printf("ending number should be > starting number\n");
	}
	
	
