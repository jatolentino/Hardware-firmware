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
	
	
	printf("Even numbers are :\n";
		even = 0;

		while(start_num <= end_num){
			if(!(start_num % 2) ){
				printf("4%d\t",start_num); //make #s take 4 places
				even++;
			}
			start_num++
		}
		printf("\ntotal even numbers: %u\n",even);
		wait_input();
}
void wait_input(void){
	printf("Please hit enter");
	while( getchar() != '\n'){
	}
	getchar();
}
