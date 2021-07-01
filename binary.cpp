#include<stdio.h>
int main(void)
{
	int dec,record[16],count=0;
	scanf("%d",&dec);
	if(dec==0)
		printf("%d",0);
	while(dec!=0)
	{
		record[count]=dec%2;
		dec/=2;
		count++;
	}
	count--;
	while(count>=0){
		printf("%d",record[count]);
		count--;
	}
	printf("\n");
	return 0;
}
