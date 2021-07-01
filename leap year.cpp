#include<stdio.h>
int main(void)
{
	int y;
	scanf("%d",&y);
	
	if(y%4==0){
		if(y%100!=0)
			printf("leap year.\n");
		else{
			if(y%400!=0)
				printf("non-leap year.\n");
			else
				printf("leap year.\n");			
		}
	}else
		printf("non-leap year.\n");
	return 0;
}
